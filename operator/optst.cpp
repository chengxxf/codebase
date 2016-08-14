#include "optst.h"
#include <iostream>
#include <stdio.h>

Sale_data operator+(const Sale_data &data1,const Sale_data &data2)
{
	Sale_data sum;

	sum.price=data1.price+data2.price;
	return sum;
}

Sale_data::Sale_data(int n)
{
	price=n;
}


void Sale_data::showPrice()
{
		printf("test \n");
		std::cout<<"sale price "<<price<<std::endl;
}
