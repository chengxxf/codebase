#include "test.h"
#include <stdio.h>

void func()
{
	printf("[func 0 ] addr %x\n",func);
}

void func1()
{
	printf("[func 1 ] addr %x\n",func1);
	func2();
}

void func2()
{
	printf("[func 2 ] addr %x\n",func2);
	func3();
}

void func3()
{
	printf("[func 3 ] addr %x\n",func3);
	funcEnd();
}

void funcEnd()
{
	printf("[funcEnd ] addr %x\n",funcEnd);
	exeTrace();
}

void setPrintTrace(PFn fn)
{
	printf("set PrintTrace %x \n",fn);
	g_PrintTrace=fn;
}

void exeTrace()
{
	if(g_PrintTrace!=0)
		g_PrintTrace();
}
