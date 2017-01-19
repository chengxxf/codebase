CC := g++
CFLAGS := -g -Wall

SRCS :=$(wildcard *.cpp)
OBJS :=$(patsubst %cpp,%o,$(SRCS))

TARGET :=simplesniffer

all:$(TARGET)
	

$(TARGET):$(OBJS)
	$(CC)  $(CFLAGS) -lpcap -lpthread -o $@ $^


abstractRx.o :abstractRx.cpp abstractRx.h
	@echo "abstractRx.o :abstractRx.cpp abstractRx.h" 
	$(CC) $(CFLAGS) -c $<

pcapRx.o:pcapRx.cpp pcapRx.h
	$(CC) $(CFLAGS) -c $<
%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)

