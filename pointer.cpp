#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include "luxstd.h"

typedef struct TMO_DLL_NODE{
	struct TMO_DLL_NODE *pNext;
	struct TMO_DLL_NODE *pPrev;
}tTMO_DLL_NODE;

typedef struct TMO_DLL{
	tTMO_DLL_NODE Head;
	int u4_Count;
	int u4_Offset;
}tTMO_DLL;

#define	VLAN_PORTS_PER_BYTE 8
unsigned char  gau1PortBitMaskMap[VLAN_PORTS_PER_BYTE] =
    { 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02};

#define TMO_DLL_Add(pList,pNode) \
	TMO_DLL_Insert_In_Middle((pList),(pList)->Head.pPrev,(pNode),&(pList)->Head)

#ifdef __STDC__
void TMO_DLL_Insert_In_MIddle(tTMO_DLL * pList,tTMO_DLL_NODE *pPrev,
		tTMO_DLL_NODE *pMid,tTMO_DLL_NODE *pNext)
#else
void TMO_DLL_Insert_In_MIddle(pList,pPrev,pMid,pNext)
		tTMO_DLL *pList;
		tTMO_DLL_NODE *pPrev;
		tTMO_DLL_NODE *pMid;
		tTMO_DLL_NODE *pNext;
#endif
{
	pList->u4_Count++;
	pMid->pNext=pNext;
	pMid->pPrev=pPrev;
	pPrev->pNext=pMid;
	pNext->pPrev=pMid;

}

typedef struct ST_TEST
{
	int a;
	int b;
	int c;

}S_TEST; 

void test_offset()
{
	printf("test offset of b %d \n",STRUCT_OFFSETOF(ST_TEST,b));

}

int main(int argc ,char *argv[]){

#ifdef __STDC__
	printf("test pointer stdc ----------\n");
#else
	printf("test pointer not ?????????stdc\n");
#endif

#ifdef __cplusplus
	printf("define cplus cplus \n");
#endif
	
	unsigned short u2Port=0;
	//u2Port -=1;
	printf("next line maybe crash %d \n",__LINE__);
	if(gau1PortBitMaskMap[u2Port])
	{
	     printf("is valid address ?test ushort 0-1 %d %x",u2Port,u2Port);
	}
	else
	{
	    printf(" is valid address ?test ushort 0-1 %d %x",u2Port,u2Port);

	}	

	
	test_offset();
	int sDLL_NODE=sizeof(TMO_DLL_NODE);
	int sTMO_DLL=sizeof(TMO_DLL);
	tTMO_DLL *pActiveList=(tTMO_DLL *) malloc(sizeof(sTMO_DLL)*10);	

	printf("the pointer size %d \n",sizeof(char *));
	printf("TMO DLL NODE size %d \n",sDLL_NODE);
	printf("TMO DLL size %d \n",sTMO_DLL);

	printf("the list address %d \n",pActiveList);
	printf("the list address %d \n",pActiveList+1);

	free(pActiveList);
	while(1)
	{
		printf("sleep before\n");
		sleep(2);
		printf("sleep end\n");
	}

	return 0;
}
