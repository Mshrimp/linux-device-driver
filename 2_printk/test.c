#include <linux/module.h>

int test_init(void)
{
	printk("<0>" "level 0\n");
	printk("<1>" "level 1\n");
	printk("<2>" "level 2\n");
	printk("<3>" "level 3\n");
	printk("<4>" "level 4\n");
	printk("<5>" "level 5\n");
	printk(KERN_INFO "level 6\n");
	printk("<7>" "level 7\n");
	return 0;
}

void test_exit(void)
{
	printk("Cleanup module\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mshrimp chiyuan.ma@outlook.com");
MODULE_VERSION("0.1");



