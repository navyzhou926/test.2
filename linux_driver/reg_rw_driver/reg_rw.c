#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <asm/io.h>

#include <linux/miscdevice.h>
#include <linux/delay.h>
#include <asm/arch/hardware.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <linux/string.h>
#include <linux/list.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <asm/unistd.h>


#define DRIVER_VERSION "v1.0"
#define DRIVER_AUTHOR "NAVY"
//#define DRIVER_DESC  "Just for test"

#define DEVICE_NAME "register_rw"

#define REG_READ  0
#define REG_WRITE 1

MODULE_AUTHOR(DRIVER_AUTHOR);
//MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("GPL");

typedef struct register_rw
{
    unsigned int reg;
    unsigned int value;
}reg_rw;

static int register_ioctl(struct inode *inode, struct file *file, unsigned int cmd, reg_rw *arg)
{
    switch(cmd) 
    {
        case REG_READ:  //read
            arg->value = inl(IO_ADDRESS(arg->reg));
            //printk("read: 0x%x\n",arg->value);
            break;
        case REG_WRITE:  //write
            outl(arg->value, IO_ADDRESS(arg->reg));
            //printk("write: 0x%x\n",arg->value);
            break;
        default:
            return -EINVAL;
    }
    return 0;
}


static struct file_operations register_fops =
{
    .owner = THIS_MODULE,
    .ioctl = register_ioctl,
};


static struct miscdevice register_read_write = 
{
    .minor = MISC_DYNAMIC_MINOR, //动态设备号
    .name = DEVICE_NAME,
    .fops = &register_fops,
};


static int register_read_write_init(void)
{
    int ret = 0;

    printk(KERN_ALERT"register read&write!\n");
    ret = misc_register(&register_read_write);
    if (ret < 0) 
    {
        printk(DEVICE_NAME"register failed!\n");
        return ret;
    }

    return 0;
}

static void register_read_write_exit(void)
{
    misc_deregister(&register_read_write);
}

module_init(register_read_write_init);
module_exit(register_read_write_exit);

//MODULE_LICENSE("Dual BSD/GPL")

