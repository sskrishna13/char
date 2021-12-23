#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

int ValueETX, arr_valueETX[4];
char *nameETX;
int cb_valueETX = 0;

module_param (ValueETX, int, S_IRUSR | S_IWUSR);	// integer value
module_param (nameETX, charp, S_IRUSR | S_IWUSR);
module_param_array (arr_valueETX, int, NULL, S_IRUSR | S_IWUSR);

/*************************** module_param_cb () ********************************************/

int notify_param (const char *val, const struct kernel_param *kp)
{
	int res = param_set_int (val, kp);	// use helper for write variable

	if (res == 0)
	{
		printk (KERN_INFO "Callback Function called\n");
		printk (KERN_INFO "New Value of cb_valueETX = %d\n", cb_valueETX);
		return 0;
	}

	return -1;
}

const struct kernel_param_ops my_param_ops = 
{
	.set	= &notify_param,	// Use our Setter
	.get	= &param_get_int,	// and standard getter
};

module_param_cb (cb_valueETX, &my_param_ops, &cb_valueETX, S_IRUGO|S_IWUSR);

static int __init MyInit (void)
{
	int i;

	printk (KERN_INFO "ValueETX = %d \n",ValueETX);
	printk (KERN_INFO "cb_valueETX = %d \n", cb_valueETX);
	printk (KERN_INFO "NameETX = %s", nameETX);

	for (i=0; i < (sizeof arr_valueETX / sizeof (int)); i++) {
		printk (KERN_INFO "Arr_value [%d]\n",arr_valueETX[i]);
	}

	printk (KERN_INFO "Kernel Module Inserted Successfully\n");

	return 0;
}

static void __exit MyExit (void)
{
	printk (KERN_INFO "Kernel Module Removed Successfully\n");
}

module_init (MyInit);
module_exit (MyExit);

MODULE_AUTHOR ("SHRIKRISHNA SAWANGIKAR");
MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Demo for passing argument to the linux device driver");
