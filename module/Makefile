obj-m += module.o

KERNEL_DIR := /home/$(USER)/code/linux-3.5
ROOTFS	:= /home/$(USER)/nfsroot

#CROSS_COMPILE=arm-linux-
#CC=$(CROSS_COMPILE)gcc



all:
	make -C $(KERNEL_DIR) M=`pwd` modules
	@#mkdir target
	@#mv *.mod.* *.o *.o* *.sym* target -f


clean:
	make -C $(KERNEL_DIR) M=`pwd` clean
	@#rm target -rf
	@#rm *.ko


install:
	make -C $(KERNEL_DIR) M=`pwd` module_install INSTALL_MOD_PATH=$(ROOTFS) 
	


