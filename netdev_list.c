/**
* Description: kenrel module to list all available network interfaces
* Date: 3-2-2015
*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netdevice.h>

MODULE_AUTHOR("Jagadeesh Pagadala");
MODULE_LICENSE("GPL");

static int netdev_list_init(void)
{
	struct net_device *dev;
		
	dev = first_net_device(&init_net);
	while(dev) {
		printk(KERN_INFO"device/interface name %s \n",dev->name);
		dev = next_net_device(dev);
	}
	return 0;
}

static void netdev_list_exit(void)
{
	
}

module_init(netdev_list_init);
module_exit(netdev_list_exit);
