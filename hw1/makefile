all:	check

default: check

clean:
	rm -rf myckpt context_ckpt restart hello ckpt ckpt.o libckpt.a test

libckpt:
	gcc -c -o ckpt.o ckpt.c && ar rcs libckpt.a ckpt.o

prog:	libckpt
	gcc -g -static -L`pwd` -lckpt -Wl,-u,init_signal -o test test.c

rst:	prog
	gcc -g -static -Wl,-Ttext-segment=5000000 -Wl,-Tdata=5100000 -Wl,-Tbss=5200000 -o restart restart.c

res:
	./restart myckpt

gdb:
	gdb --args ./restart myckpt

check:	clean rst
	(sleep 3 && kill -12 `pgrep -n test` && sleep 2 && pkill -9 test) &
	./test
	(sleep 2 &&  pkill -9 restart) &
	make res

dist:
	dir=`basename $$PWD`; cd ..; tar cvf $$dir.tar ./$$dir; gzip $$dir.tar