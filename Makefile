obj-m	:= netdev_list.o 
KDIR	:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
ccflags-y:= -Wno-declaration-after-statement -Wno-unused-value

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
install:
	insmod hook.ko
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
