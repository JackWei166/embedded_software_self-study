#include <linux/module.h>
#include <linux/kernel.h>

int gx = 10;

EXPORT_SYMBOL(gx);

int __init modulea_init(void){
	printk("in modulea init gx = %d\n", gx);

	return 0;
}

void __exit modulea_exit(void){   //xxx 注意把原来的名字全替换了
	printk("modulea will exit\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jack");
MODULE_DESCRIPTION("This is a modulea program.");
MODULE_ALIAS("modulea");

module_init(modulea_init);
module_exit(modulea_exit);   //xxx 把别的代码改成自己的，注意所有变化，全部体现，最后在浏览一遍！！！（这里模块名字变了，没全部体现，估计可能导致前面的问题 一会儿回去再试试吧）
