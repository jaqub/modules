### Automatic Makefile generation by 'genmake' script        ####
### Copyright, Jerry Cooperstein, coop@linuxfoundation.org 2/2003 - 1/2014 ####
### License: GPLv2 ###

obj-m +=  pdev.o
obj-m +=  pdrv.o

export KROOT=/home/jakub/Workspace/linux/

allofit:  modules
modules:
	@$(MAKE) -C $(KROOT) M=$(shell pwd) modules
modules_install:
	@$(MAKE) -C $(KROOT) M=$(shell pwd) modules_install

clean:
	@$(MAKE) -C $(KROOT) M=$(PWD) clean

