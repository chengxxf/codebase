
TARGET_SUFIX=bin

all:pointer${TARGET_SUFIX}
	echo 
	
pointer${TARGET_SUFIX}: pointer.cpp
	gcc -o pointer pointer.cpp

clean:
	rm pointer 
