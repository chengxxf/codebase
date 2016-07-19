
all: backtrace.c testlib
	make name

name:backtrace.c
	gcc backtrace.c -rdynamic -L. -ltest -o backtrace

skip:backtrace.c 
	gcc backtrace.c -L. -ltest -o backtrace
testlib:
	gcc test.c -fPIC -shared  -o libtest.so
	make copyso
copyso:libtest.so
	cp libtest.so /home/test/libdir
