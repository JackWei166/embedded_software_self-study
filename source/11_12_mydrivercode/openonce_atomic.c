#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/kdev_t.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <asm/atomic.h>

int devno;
int minor = 0;
int major;
int openonce_num = 1;

struct openonce_dev {
	struct cdev mydev;
	
	atomic_t openflag;
} gmydev;

int openonce_open(struct inode *pnode, struct file *pfile){
	struct openonce_dev *pmydev;

	//pfile->private_data = (void *)(container_of(pnode->i_cdev, struct openonce_dev, mydev);
	pfile->private_data = container_of(pnode->i_cdev, struct openonce_dev, mydev);

	pmydev = pfile->private_data;

	printk("openonce_open is called\n");

	if (atomic_dec_and_test(&pmydev->openflag)){
		return 0;
	} else {
		atomic_inc(&pmydev->openflag);
		printk("open already\n");
		return -1;
	}
	
	return 0;
}

int openonce_close(struct inode *pnode, struct file *pfile){
	struct openonce_dev *pmydev = pfile->private_data;
	
	printk("openonce_close is called\n");
	
	atomic_inc(&pmydev->openflag);

	return 0;
}

struct file_operations myops = {
	.owner = THIS_MODULE,
	.open = openonce_open,
	.release = openonce_close,
};

int __init openonce_init(void){
	int ret;

	ret = alloc_chrdev_region(&devno, minor, openonce_num, "openonce");
	if (ret != 0) {
		printk("get devno failed.\n");
		return -1;
	}
	
	cdev_init(&gmydev.mydev, &myops);
	gmydev.mydev.owner = THIS_MODULE;
	cdev_add(&gmydev.mydev, devno, openonce_num);
	
	atomic_set(&gmydev.openflag, 1);

	return 0;
}

void __exit openonce_exit(void){
	cdev_del(&gmydev.mydev);

	unregister_chrdev_region(devno, openonce_num);
}

MODULE_LICENSE("GPL");

module_init(openonce_init);
module_exit(openonce_exit);
