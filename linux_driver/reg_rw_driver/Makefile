#KERNEL_MAKE :=/opt/mv_pro_4.0.1/montavista/pro/devkit/lsp/ti-davinci/linux-2.6.10_mvl401_LSP_01_30_00_082
#KERNEL_MAKE :=/opt/linux-2.6.18_pro500
KERNEL_MAKE :=/opt/linux-2.6.18_pro500_20111223_V1.2.2

PWD:=$(shell pwd)

CROSS_ARCH:=ARCH=arm CROSS_COMPILE=arm_v5t_le-

#CROSS_COMPILE=arm_v5t_le-
#CC=$(CROSS_COMPILE)gcc

obj-m := reg_rw.o
#reg_rw-y += reg_rw.o


modules:
	$(MAKE) $(CROSS_ARCH) -C $(KERNEL_MAKE) M=$(PWD) modules
	#$(MAKE) -C $(KERNEL_MAKE) M=$(PWD) modules
	cp reg_rw.ko /home/navyzhou/tftp

clean:
	rm -rf *.o *.ko
