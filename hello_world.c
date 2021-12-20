#include <linux/init.h>		// Needed for the macro
#include <linux/module.h>	// Needed by all modules
#include <linux/kernel.h>	// Needed for KERN_INFO


static int __init MyInit(void)		// Constructor
{
	printk ("I am in Init Function\n");
	printk (KERN_INFO "Hello :: Module is loading");

	return 0;
}

static void __exit MyExit(void)		// Destructor
{
	printk (KERN_INFO "I am in Exit Function\n");
	printk (KERN_INFO "Bye :: Module is removing\n");

	
}

module_init (MyInit);
module_exit (MyExit);

MODULE_AUTHOR ("Shrikrishna-Sawangikar");
MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("A Simple Hello World Driver");

