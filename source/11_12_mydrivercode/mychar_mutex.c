#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include "mychar.h"
#include <linux/kdev_t.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/mutex.h>
#include <linux/mm.h>
#include <linux/slab.h>

#define BUF_LEN 100
#define MYCHAR_DEV_CNT 3

int devno;
int minor = 0;
int major;
int mychar_num = MYCHAR_DEV_CNT;

struct mychar_dev {
	struct cdev mydev;
	
	char mydev_buf[BUF_LEN];
	int curlen;

	wait_queue_head_t rq;
	wait_queue_head_t wq;

	struct fasync_struct *pasync_obj;

	struct mutex lock;
} *pgmydev[MYCHAR_DEV_CNT];

int mychar_open(struct inode *pnode, struct file *pfile){
	//pfile->private_data = (void *)(container_of(pnode->i_cdev, struct mychar_dev, mydev);
	pfile->private_data = container_of(pnode->i_cdev, struct mychar_dev, mydev);

	printk("mychar_open is called\n");
	
	return 0;
}

int mychar_close(struct inode *pnode, struct file *pfile){
	struct mychar_dev *pmydev = pfile->private_data;
	
	printk("mychar_close is called\n");
	
	if (pmydev->pasync_obj) {
		fasync_helper(-1, pfile, 0, &pmydev->pasync_obj);
	}

	return 0;
}

ssize_t mychar_read(struct file *pfile, char __user *puser, size_t count, loff_t *p_pos){
	int size;
	int ret;
	
	//struct mychar_dev *pmydev = (struct mychar_dev *)pfile->private_data;
	struct mychar_dev *pmydev = pfile->private_data;
	
	mutex_lock(&pmydev->lock);
	if (pmydev->curlen <= 0) {
		if (pfile->f_flags & O_NONBLOCK) {
			mutex_unlock(&pmydev->lock);
			printk("O_NONBLOCK No Data Read\n");
			return -1;
		} else {
			mutex_unlock(&pmydev->lock);
			ret = wait_event_interruptible(pmydev->rq, pmydev->curlen > 0);
			if (ret != 0) {
				printk("Wake up by signal\n");
				return -ERESTARTSYS;
			}
		}
	}

	mutex_lock(&pmydev->lock);
	if (count > pmydev->curlen) {
		size = pmydev->curlen;
	} else {
		size = count;
	}

	ret = copy_to_user(puser, pmydev->mydev_buf, size);
	if (ret == 1) {
		mutex_unlock(&pmydev->lock);
		printk("copy_to_user is failed.");
		return -1;
	}

	memcpy(pmydev->mydev_buf, pmydev->mydev_buf + size, pmydev->curlen - size);
	pmydev->curlen = pmydev->curlen -size;
	
	mutex_unlock(&pmydev->lock);
	wake_up_interruptible(&pmydev->wq);

	return size;
}

ssize_t mychar_write(struct file *pfile, const char __user *puser, size_t count, loff_t *p_pos){
	int size;
	int ret;

	//struct mychar_dev *pmydev = (struct mychar_dev *)pfile->private_data;
	struct mychar_dev *pmydev = pfile->private_data;
	
	mutex_lock(&pmydev->lock);
	if (pmydev->curlen >= BUF_LEN) {
		if (pfile->f_flags & O_NONBLOCK) {
			mutex_unlock(&pmydev->lock);
			printk("O_NONBLOCK No Data Write\n");
			return -1;
		} else {
			mutex_unlock(&pmydev->lock);
			ret = wait_event_interruptible(pmydev->wq, pmydev->curlen < BUF_LEN);
			if (ret != 0) {
				printk("Wake up by signal\n");
				return -ERESTARTSYS;
			}
			mutex_lock(&pmydev->lock);
		}
	}

	if (count > BUF_LEN - pmydev->curlen) {
		size = BUF_LEN - pmydev->curlen;
	} else {
		size = count;
	}

	ret = copy_from_user(pmydev->mydev_buf + pmydev->curlen, puser, size);
	if (ret == 1) {
		mutex_unlock(&pmydev->lock);
		printk("copy_from_user is failed.\n");
		return -1;
	}
	pmydev->curlen = pmydev->curlen + size;

	mutex_unlock(&pmydev->lock);
	wake_up_interruptible(&pmydev->rq);

	if (pmydev->pasync_obj) {
		kill_fasync(&pmydev->pasync_obj, SIGIO, POLLIN);
	}

	return size;
}

long mychar_ioctl(struct file *pfile, unsigned int cmd, unsigned long arg){
	int ret;
	int __user *pret = (int *)arg;
	struct mychar_dev *pmydev = pfile->private_data;
	int maxlen = BUF_LEN;

	switch (cmd) {
	case MYCHAR_IOCTL_GET_MAXLEN:
		ret = copy_to_user(pret, &maxlen, sizeof(int));
		if (ret) {
			printk("copy to user maxlen failed.\n");
			return -1;
		}
		break;
	case MYCHAR_IOCTL_GET_CURLEN:
		mutex_lock(&pmydev->lock);
		ret = copy_to_user(pret, &pmydev->curlen, sizeof(int));
		mutex_unlock(&pmydev->lock);
		if (ret) {
			printk("copy to user curlen failed,\n");
			return -1;
		}
		break;
	default:
		printk("The cmd is unknown.\n");
		return -1;
	}

	return 0;
}

unsigned int mychar_poll(struct file *pfile, poll_table *ptb){
	unsigned int mask = 0;
	struct mychar_dev *pmydev = pfile->private_data;

	poll_wait(pfile, &pmydev->rq, ptb);
	poll_wait(pfile, &pmydev->wq, ptb);
	
	mutex_lock(&pmydev->lock);
	if (pmydev->curlen > 0) {
		mask |= POLLIN | POLLRDNORM;
	}
	if (pmydev->curlen < BUF_LEN) {
		mask |= POLLOUT | POLLWRNORM;
	}
	mutex_unlock(&pmydev->lock);

	return mask;
}

int mychar_fasync(int fd, struct file *pfile, int mode){
	struct mychar_dev *pmydev = pfile->private_data;

	return fasync_helper(fd, pfile, mode, &pmydev->pasync_obj);
}

struct file_operations myops = {
	.owner = THIS_MODULE,
	.open = mychar_open,
	.release = mychar_close,
	.read = mychar_read,
	.write = mychar_write,
	.unlocked_ioctl = mychar_ioctl,
	.poll = mychar_poll,
	.fasync = mychar_fasync,
};

int __init mychar_init(void){
	int ret, i;

	ret = alloc_chrdev_region(&devno, minor, mychar_num, "mychar_mutex");
	if (ret != 0) {
		printk("get devno failed.\n");
		return -1;
	}
	major = MAJOR(devno);
	
	for (i = 0;i < MYCHAR_DEV_CNT; i++) {
		pgmydev[i] = (struct mychar_dev *)kmalloc(sizeof(struct mychar_dev), GFP_KERNEL);

		devno = MKDEV(major, minor+i);

		cdev_init(&pgmydev[i]->mydev, &myops);
		pgmydev[i]->mydev.owner = THIS_MODULE;
		cdev_add(&pgmydev[i]->mydev, devno, mychar_num);

		init_waitqueue_head(&pgmydev[i]->rq);
		init_waitqueue_head(&pgmydev[i]->wq);
		
		mutex_init(&pgmydev[i]->lock);
	}

	return 0;
}

void __exit mychar_exit(void){
	int i;

	for (i = 0; i < MYCHAR_DEV_CNT; i++) {
		cdev_del(&pgmydev[i]->mydev);

		kfree(pgmydev[i]);
		pgmydev[i] = NULL;
	}

	unregister_chrdev_region(devno, mychar_num);
}

MODULE_LICENSE("GPL");

module_init(mychar_init);
module_exit(mychar_exit);
