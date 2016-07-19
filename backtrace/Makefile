
all: backtrace.c testlib
	gcc backtrace.c -L. -ltest -m32 -o backtrace

name:backtrace.c
	gcc backtrace.c -g -rdynamic -L. -ltest -o backtrace

testlib:
	gcc test.c -fPIC -shared -m32 -o libtest.so
	make copyso
copyso:libtest.so
	cp libtest.so /home/test/libdir
