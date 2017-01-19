#include "str_tst.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
void test_struct()
{

	tEcfmCcMsg *pQMsg;

	pQMsg=(tEcfmCcMsg *)malloc(sizeof(tEcfmCcMsg));
	memset(pQMsg,0,sizeof(tEcfmCcMsg));

	pQMsg->uMsg.Mep.u1MdLevel=1;
	cout<<"test struct"<<endl;
	cout<<"md level \""<<(pQMsg->uMsg.Mep.u1MdLevel)<<"\";"<<endl;
	printf("md %d \n",pQMsg->uMsg.Mep.u1MdLevel);

	free(pQMsg);

}
