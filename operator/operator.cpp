
#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <iterator>

#define TST_CPLUS

#ifdef TST_CPLUS
#include "optst.h"
#endif
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

int main(int argc,char *argv[])
{
	printf("operator begin \n");
	test_pointer_def();
	typename_test();
#ifdef TST_CPLUS
	Sale_data data(1) ,data1(2),data2(3);
	data.showPrice();
	data1.showPrice();
	data2.showPrice();
	
#endif

	return 0;
}
