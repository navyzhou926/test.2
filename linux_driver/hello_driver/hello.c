#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/kernel.h>

#define DRIVER_VERSION "v1.0"
#define DRIVER_AUTHOR "NAVY"
#define DRIVER_DESC  "Just for test"

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("GPL");

static int hello_init(void)
{
    printk(KERN_ALERT"Hello Navy !\n");

    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT"Goodbye Navy !\n");
}

module_init(hello_init);
module_exit(hello_exit);

//MODULE_LICENSE("Dual BSD/GPL")

