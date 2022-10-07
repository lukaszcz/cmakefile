all: mylib myprog

mylib:
	$(MAKE) -f Makefile.generic CONFIG=MYLIB

myprog: mylib
	$(MAKE) -f Makefile.generic CONFIG=MYPROG

clean:
	$(MAKE) -f Makefile.generic clean

.PHONY: mylib myprog clean
