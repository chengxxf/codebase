#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

void print_trace(void)
{

	void *array[10];
	size_t size;
	char **strings;
	size_t i;

	size=backtrace(array,10);

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
	print_trace();
}

void test()
{
	func();
	func1();
	func2();
	func3();

}

int main(int argc,char *argv[])
{


	dummy_function();
	return 0;
}




