//#include <linux/moduleparam.h>
//#include <linux/printk.h>
#include <linux/module.h>
//#include <linux/init.h>
#include <linux/kernel.h>

int gx = 100;
char *gstr = "hello";
int garr[6] = {1, 2, 3, 4, 5, 6};   //xxx 报错说h中的问题，很可能是源文件调用周围的问题！

module_param(gx, int, 0664);
module_param(gstr, charp, 0664);
module_param_array(garr, int, NULL, 0664);

int __init testparam_init(void){
	int i;

	printk("%d\n", gx);
	
	printk("%s\n", gstr);
	
	for(i = 0; i < 6; i++){
		printk("%d ", garr[i]);
	}
	printk("\n");

	return 0;
}

void __exit testparam_exit(void){
	printk("testparam will exit\n");
}

MODULE_LICENSE("GPL");

module_init(testparam_init);
module_exit(testparam_exit);
