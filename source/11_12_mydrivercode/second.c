#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/wait.h>
#include <linux/device.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>

int major;
int minor = 0;
int mysecond_num = 1;

struct mysecond_dev {
	struct cdev mydev;

	int second;
	struct timer_list timer;

	atomic_t openflag;
} gmydev;

void timer_func(unsigned long arg){
	struct mysecond_dev *pmydev = (struct mysecond_dev *)arg;

	pmydev->second++;

	mod_timer(&pmydev->timer, jiffies + HZ * 1);
}

int mysecond_open(struct inode *pnode, struct file *pfile){
	struct mysecond_dev *pmydev;

	pfile->private_data = container_of(pnode->i_cdev, struct mysecond_dev, mydev);
	pmydev = pfile->private_data;

	if (atomic_dec_and_test(&pmydev->openflag)) {
		pmydev->timer.expires = jiffies + HZ * 1;
		pmydev->timer.function = timer_func;
		pmydev->timer.data = (unsigned long)pmydev;

		add_timer(&pmydev->timer);

		return 0;
	} else {
		atomic_inc(&pmydev->openflag);
		printk("The device is opened already");
		return -1;
	}

	return 0;
}

int mysecond_close(struct inode *pnode, struct file *pfile){
	struct mysecond_dev *pmydev = pfile->private_data;

	del_timer(&pmydev->timer);

	atomic_set(&pmydev->openflag, 1);
	
	return 0;
}

ssize_t mysecond_read(struct file *pfile, char __user *puser, size_t size, loff_t *p_pos){
	struct mysecond_dev *pmydev = pfile->private_data;
	int ret;
	
	if (size < sizeof(int)) {
		printk("the expect read size is invalid\n");
		return -1;
	}

	if (size >= sizeof(int)) {
		size = sizeof(int);
	}

	ret = copy_to_user(puser, &pmydev->second, size);
	if (ret) {
		printk("copy to user failed.\n");
		return -1;
	}
	return size;
}

struct file_operations myops = {
	.owner = THIS_MODULE,
	.open = mysecond_open,
	.release = mysecond_close,
	.read = mysecond_read,
};

int __init mysecond_init(void){
	int ret;
	dev_t devno;

	ret = alloc_chrdev_region(&devno, minor, mysecond_num, "mysecond");
	if (ret) {
		printk("get devno failed.\n");
		return -1;
	}
	major = MAJOR(devno);

	cdev_init(&gmydev.mydev, &myops);
	gmydev.mydev.owner = THIS_MODULE;
	cdev_add(&gmydev.mydev, devno, mysecond_num);

	init_timer(&gmydev.timer);
	atomic_set(&gmydev.openflag, 1);

	return 0;
}

void __exit mysecond_exit(void){
	dev_t devno = MKDEV(major, minor);

	cdev_del(&gmydev.mydev);

	unregister_chrdev_region(devno, mysecond_num);
}

MODULE_LICENSE("GPL");

module_init(mysecond_init);
module_exit(mysecond_exit);
