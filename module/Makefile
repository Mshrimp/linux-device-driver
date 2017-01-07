obj-m += module.o

KERNEL_DIR := /home/kevin/code/linux-3.5
CROSS_COMPILE=arm-linux-
CC=$(CROSS_COMPILE)gcc



all:
	make -C $(KERNEL_DIR) M=`pwd` modules


clean:
	make -C $(KERNEL_DIR) M=`pwd` clean






