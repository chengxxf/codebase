.PHONY:clean


SRCS :=$(wildcard *.cpp)
OBJS :=$(patsubst %cpp,%o,$(SRCS))

all: $(OBJS)
	g++ -o out $^
optst.o: optst.cpp optst.h
	g++ -c optst.cpp -o optst.o

operator.o: oper_main.cpp multiply_bytes.o
	g++ -c oper_main.cpp -o operator.o
str_tst.o:str_tst.cpp str_tst.h
	g++ -c str_tst.cpp -o str_tst.o

%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -rf *.o
	rm out
