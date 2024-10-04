#include <linux/module.h>
#include <linux/kernel.h>

int __init myhello_init(void){
	printk("########################\n");
	printk("########################\n");
	printk("myhello is running\n");
	printk("########################\n");
	printk("########################\n");

	return 0;
}

void __exit myhello_exit(void){
	printk("myhello will exit\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jack");
MODULE_DESCRIPTION("This is a hello program.");
MODULE_ALIAS("Hi");

module_init(myhello_init);
module_exit(myhello_exit);
