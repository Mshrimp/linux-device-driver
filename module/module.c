#include <linux/init.h>
#include <linux/module.h>


static int test_init(void)
{
	printk("Hello linux device driver!\n");

	return 0;
}


static void test_exit(void)
{
	printk("Goodbye, see you next time!\n");
}



module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");

