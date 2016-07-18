##generate libtest.so

gcc test.c -fPIC -shared -o libtest.so

##read sysbols
readelf -s *.so

objdump -t *.so

objdump -tT *.so
