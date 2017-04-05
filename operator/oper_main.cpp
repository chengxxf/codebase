
#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <iterator>

#include "str_tst.h"
#include "cast_oper.h"
#include "test.h"


#include <stdarg.h>

#define TST_CPLUS

#ifdef TST_CPLUS
#include "optst.h"
#endif

#define UINT4 unsigned int
#define MOD_TRC(u4DbgVar,mask,moduleName,fmt)  UtlTrcLog(u4DbgVar, \
                                                mask,               \
                                                moduleName,         \
                                                fmt)

#define TCP_MOD_TRC MOD_TRC

void UtlTrcLog(UINT4 u4Flag, UINT4 u4Value, const char *pi1Name, const char *pi1Fmt, ...)
{

    if (!(u4Flag & u4Value))
    {
		printf("in utltrcLog flag is not set \n");
        return;
    }

	va_list             VarArgList;
    va_start (VarArgList, pi1Fmt);

	vprintf(pi1Fmt,VarArgList);
    va_end(VarArgList);

}

void test_pointer_def()
{
	int *a1,b1;
	int a2,*b2;
	int i=1;
	b1=i;
	a1=&i;
	a2=i;
	b2=&i;
	printf("b1 %d and a2 %d is int \n",b1,a2);
	printf("b2 %d and a1 %d is pointer \n",b2,a1);
}

void typename_test()
{
	int temp(1);
	printf("int temp(1) is %d \n",temp);
}
template<typename IterT>
void workWithIterator(IterT iter)
{
	typename std::iterator_traits<IterT>::value_type temp(*iter);
}

void test_trace1()
{
#define TCP_ENTRY_EXIT_TRC 0x00000100
#define TCP_ALL_FAIL_TRC   0x00000040

	unsigned int debugLevel=65535;

	unsigned int flag=debugLevel;

	unsigned int u4Value=TCP_ENTRY_EXIT_TRC |TCP_ALL_FAIL_TRC; 

	if(!(flag & u4Value)){
		printf("flag not set\n");

	
	}
	else{

		printf("flags set %08x \n",(flag & u4Value));
	}

	TCP_MOD_TRC (debugLevel, TCP_ENTRY_EXIT_TRC | TCP_ALL_FAIL_TRC, "TCP",
                 "Exit from LINInpFindConnection. Returned ERR.\n");

}

int main(int argc,char *argv[])
{
	printf("operator begin \n");
	//test_u4();
	test_pointer_def();
	typename_test();
    multiply_test(999,999);
#ifdef TST_CPLUS
	Sale_data data(1) ,data1(2),data2(3);
	data.showPrice();
	data1.showPrice();
	data2.showPrice();
	
#endif
	test_struct();
    test_trace1();
    while(1){
        sleep(2);
    }	


	return 0;
}
