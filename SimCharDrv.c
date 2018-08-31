/*
 * Pradeepkumar.orgMain menu
Embedded Systems
Lectures
Linux Kernel Programming
Network Simulator 2
video
Network Simulators
About Me
FEED COUNT


Writing a Simple Character Device driver in Linux by tspradeepkumar • 25 March, 2010 • Linux, Linux Kernel Programming • 6 Comments
A Character device driver needs a major number and a minor number. The devices are registered in the Kernel and it lies either in the /dev/ or in the /proc folder.

The following example uses a char device driver with major number 222 and a minor number 0. The name of the device driver namely “new_device”

It uses the following things

Open or register a device

close or unregister the device

Reading from the device (Kernel to the userspace)

Writing to the device (userlevel to the kernel space)



There are three files, Copy the following or download all the three files here

/* new_dev.c*/

#include
#include
#include “new_dev.h”

MODULE_AUTHOR(“PRADEEPKUMAR”);
MODULE_DESCRIPTION(“A simple char device”);

static int r_init(void);
static void r_cleanup(void);

module_init(r_init);
module_exit(r_cleanup);

static int r_init(void)
{
    printk(“<1>hi\n”);
    if(register_chrdev(222,”new_device”,&my_fops)) {
        printk(“<1>failed to register”);
    }
    return 0;
}
static void r_cleanup(void)
{
    printk(“<1>bye\n”);
    unregister_chrdev(222,”new_device”);
    return ;
}

/*new_dev.h */

/*
* my device header file
*/
#ifndef _NEW_DEVICE_H
#define _NEW_DEVICE_H

#include
#include
#include
#include
#include
#include

char my_data[80]=”hi from kernel”; /* our device */

int my_open(struct inode *inode,struct file *filep);
int my_release(struct inode *inode,struct file *filep);
ssize_t my_read(struct file *filep,char *buff,size_t count,loff_t *offp );
ssize_t my_write(struct file *filep,const char *buff,size_t count,loff_t *offp );
struct file_operations my_fops= {
open:
    my_open,
read:
    my_read,
write:
    my_write,
release:
    my_release,
};

int my_open(struct inode *inode,struct file *filep)
{
    /*MOD_INC_USE_COUNT;*/ /* increments usage count of module */
    return 0;
}

int my_release(struct inode *inode,struct file *filep)
{
    /*MOD_DEC_USE_COUNT;*/ /* decrements usage count of module */
    return 0;
}
ssize_t my_read(struct file *filep,char *buff,size_t count,loff_t *offp )
{
    /* function to copy kernel space buffer to user space*/
    if ( copy_to_user(buff,my_data,strlen(my_data)) != 0 )
        printk( “Kernel -> userspace copy failed!\n” );
    return strlen(my_data);

}
ssize_t my_write(struct file *filep,const char *buff,size_t count,loff_t *offp )
{
    /* function to copy user space buffer to kernel space*/
    if ( copy_from_user(my_data,buff,count) != 0 )
        printk( “Userspace -> kernel copy failed!\n” );
    return 0;
}
#endif

/*
Makefile

obj-m += new_dev.o

all:
make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

How to compile

Put all the three files in the same folder and execute the following commands


make (to compile the module)

insmod new_dev.ko (To insert the module)



Once the module is inserted, do the following

mknod /dev/new_device c 222 0 (Command to make an entry in the /dev/, once the device is created, go and see the /dev/ folder for the entry new_device)

cat /dev/new_device (The message will be printed which is from the kernel, that is read operation)

echo “This is a write information to the kernel” > /dev/new_device (This command is to perform the write operation)

After checking the read and write operation, just remove the module

rmmod new_dev.ko

(Source: http://linuxgazette.net/125/mishra.html)
*/

