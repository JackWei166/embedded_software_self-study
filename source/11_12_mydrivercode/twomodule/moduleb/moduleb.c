#include <linux/module.h>
#include <linux/kernel.h>

extern int gx;

int __init moduleb_init(void){
	printk("in moduleb init gx = %d\n", gx);

	return 0;
}

void __exit moduleb_exit(void){
	printk("moduleb will exit\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jack");
MODULE_DESCRIPTION("This is a moduleb program.");
MODULE_ALIAS("moduleb");

module_init(moduleb_init);
module_exit(moduleb_exit);   //xxx 把别的代码改成自己的，注意所有变化，全部体现，最后在浏览一遍！！！（这里模块名字变了，没全部体现，估计可能导致前面的问题 一会儿回去再试试吧）
