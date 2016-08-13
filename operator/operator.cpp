
#include <stdio.h>

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

int main(int argc,char *argv[])
{
	printf("operator begin \n");
	test_pointer_def();


	return 0;
}
