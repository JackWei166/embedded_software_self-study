#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe00b4984, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x5eae5d6b, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xa22311d0, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x68dfc59f, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xdd353f7f, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x64e48f86, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xf82eacf7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe2cb65c5, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x20f4fdce, __VMLINUX_SYMBOL_STR(kill_fasync) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x75bb675a, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xa56d356, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x4292364c, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xe45f60d8, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x2e60bace, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x728d8849, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xfe57f7e2, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xe24abfc5, __VMLINUX_SYMBOL_STR(fasync_helper) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7540AD7365B19E6C154B147");
