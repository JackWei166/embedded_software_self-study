#include <linux/module.h>
#include <linux/kernel.h>

void test_func(void);   //xxx 注意加上！只要是陌生的都要说明来处！

int __init test_init(void){
	test_func();
	return 0;
}

void __exit test_exit(void){
	printk("test will exit\n");
}

MODULE_LICENSE("GPL");

module_init(test_init);
module_exit(test_exit);
