.PHONY:clean
all: operator.o optst.o
	g++ -o out operator.o optst.o
optst.o: optst.cpp optst.h
	g++ -c optst.cpp -o optst.o

operator.o: operator.cpp
	g++ -c operator.cpp -o operator.o

clean:
	rm -rf *.o
