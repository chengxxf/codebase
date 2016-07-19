#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "test.h"
#include "backtrace.h"

#define CRASH 1
#define SIZE 100
void print_trace(void)
{

	void *array[10];
	size_t size;
	char **strings;
	size_t i;

	size=backtrace(array,SIZE);

	strings=backtrace_symbols(array,size);
	if(NULL==strings)
	{	
		perror("backtrace_synbols");
		exit(EXIT_FAILURE);

	}

	printf("Obtained %zd stack frames.\n",size);

	for(i=0;i<size;i++)
	{
		printf("%s \n",strings[i]);

	}
	
	free(strings);
	strings=NULL;

}

void dummy_function()
{

}

void myfun()
{
	printf("[func ] myfun %x \n",myfun);
	myfun1();
}

void myfun1()
{
	printf("[func ] myfun1 %x \n",myfun1);
	myfun2();
}


void myfun2()
{
	printf("[func ] myfun2 %x \n",myfun2);	
	myfun3();
}

void myfun3()
{
	printf("[func ] myfun3 %x \n",myfun3);	
#if CRASH
	char *p=0;
	*(p+10000)=9;
#else

#endif
}

void test()
{
	setPrintTrace(print_trace);
	func();
	func1();
	while(1)
	{
		sleep(2);
	}
}

void signal_handle(int signo)
{
	printf("\n===>>>catch signal %d (%s)<<<=====\n",
					signo,strsignal(signo));
	print_trace();
	signal(signo, SIG_DFL);
}

int main(int argc,char *argv[])
{
	signal(SIGSEGV,signal_handle);
	//dummy_function();
	printf("main start\n");
	//myfun();
	test();
	return 0;
}




