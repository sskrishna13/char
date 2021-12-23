#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

char *name = "Krishna";
int loop_cnt = 1;

module_param (name, charp, S_IRUGO);
module_param (loop_cnt, int, S_IRUGO);




static int __init parameter_Init (void)
{
	int i;

	printk (KERN_INFO "%s IN INIT\n", __func__);
	printk (KERN_INFO "%s LOOP COUNT :%d\n", __func__, loop_cnt);

	for (i=0; i<loop_cnt; i++)
		printk (KERN_INFO "%s HI %s\n",__func__, name);

	return 0;
}

static void __exit parameter_Exit (void)
{
	printk (KERN_INFO "%s : In Exit\n",__func__);
}

module_init (parameter_Init);
module_exit (parameter_Exit);

MODULE_AUTHOR ("SHRIKRISHNA SAWANGIKAR");
MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("simple parameter passing to driver");
