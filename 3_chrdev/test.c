#include <linux/module.h>
#include <linux/fs.h>	

int test_open(struct inode *inodp, struct file *filp)
{
	printk("test module open\n");
	return 0;
}

int test_close(struct inode *inodp, struct file *filp)
{
	printk("test module close\n");
	return 0;
}

ssize_t test_read(struct file *filp, char __user *buf, size_t size, loff_t *offset)
{
	printk("test module read\n");

	return size;
}

ssize_t test_write(struct file *filp, const char __user *buf, size_t size, loff_t *offset)
{
	printk("test module write\n");

	return size;
}

struct file_operations fops = {
	.open = test_open,
	.release = test_close,
	.read = test_read,
	.write = test_write,
};

int major = 0;
int test_init(void)
{
	int ret = 0;
	printk("Init module\n");

	ret = register_chrdev(major, "Tiny4412_module", &fops);
	if (ret < 0)
	{
		printk("%s: line:%d register_chrdev error!\n", __func__, __LINE__);
	}

	if (major == 0)
	{
		major = ret;
	}
	printk("major = %d\n", major);

	return 0;
}

void test_exit(void)
{
	printk("Cleanup module\n");
	unregister_chrdev(major, "Tiny4412_module");
}


module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mshrimp chiyuan.ma@outlook.com");
MODULE_VERSION("0.1");
