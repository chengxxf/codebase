ifneq ($(KERNELRELEASE),)
	obj-m :=hello_driver.o
else

KERNELDIR ?=/lib/modules/$(shell uname -r)/build

PWD :=$(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

endif

clean:
	rm -rf *.o  .depend .*.
