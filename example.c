/**
* @file example.c
* @author Vladislav Semyonoff
* @date 17 March 2019
* @version 0.1
* @brief Example loadable kernel module
* Loadable Kernel Module (LKM) example that will just print info
* messages when the module is loaded and removed.
*/
#include <linux/module.h>	 /* Needed by all modules */
#include <linux/kernel.h>	 /* Needed for KERN_INFO */
#include <linux/init.h>	 /* Needed for the macros */

///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");

///< The author -- visible when you use modinfo
MODULE_AUTHOR("Vladislav Semyonoff");

///< The description -- see modinfo
MODULE_DESCRIPTION("Example kernel module");

///< The version of the module
MODULE_VERSION("0.1");

static int __init mod_init(void)
{
	printk(KERN_INFO "Loading example module...\n");
	return 0;
}

static void __exit mod_exit(void)
{
	printk(KERN_INFO "Unloading example module...\n");
} 

module_init(mod_init);
module_exit(mod_exit);
