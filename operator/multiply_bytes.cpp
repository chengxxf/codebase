#include "stdio.h"
#include <sys/types.h>

#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>


int multiply_bytes10(u_char *a,int aLen,u_char *b,int bLen, u_char **ppRes,int *pOutLen)
{
	if(ppRes==NULL || pOutLen==NULL ) return -1;
	int aIx=0,bIx=0,i=0,j=0,val,iOutLen=0;
	int tmpLen=aLen+bLen+1;
	std::vector<u_char > vec0(tmpLen,0);
    std::vector<u_char > vec1(tmpLen,0);

    //std::vector<char > vecFinal(tmpLen+1);
	std::vector<u_char > *pCurVec=&vec0;
    std::vector<u_char > * pPreVec=&vec1;
   
	int tmp,low=0,carry=0;

	for(bIx=0;bIx<bLen;bIx++)
	{
        printf("cur bIx is %d \n",bIx);

        if(bIx%2==0)
        {
           // pCurVec=&vec0;
           //pPreVec=&vec1;
        }
        else
        {
            //pCurVec=&vec1;
           // pPreVec=&vec0;
        }

        for(aIx=0;aIx<aLen;aIx++)
        {

            if(a[aIx]<10 && b[bIx]<10){

                for(i=0;i<bIx;i++)
                {
                    (*pCurVec)[i]=0;
                }

                tmp=a[aIx]*b[bIx]+carry;
                low=tmp%10;

                (*pCurVec)[aIx+bIx]=(char)low;


                carry=tmp/10;

                if(aIx==aLen-1 && carry!=0){

                    (*pCurVec)[aLen+bIx]=carry;
                }
	
            }else{

                printf(" a[%d]=0x%x b[%d]=0x%x \n",aIx,a[aIx],bIx,b[bIx]);

            }

        }

        carry=0;
        for(i=0;i<aLen+bIx+1;i++){
            tmp=(*pCurVec)[i]+(*pPreVec)[i]+carry;
            low=tmp%10;
            (*pPreVec)[i]=low;
            carry=tmp/10;

        }

        if(carry!=0){
            (*pPreVec)[aLen+bIx+1]=carry;

        }           

	}

    
    for(i=aLen+bLen;i>=0;i--){
        if(0!=(*pPreVec)[i]){
            break;
        }

    }

    iOutLen=i+1;
    *pOutLen=iOutLen;

    *ppRes=(u_char *)malloc(*pOutLen);       
    
    for(i=0;i<iOutLen;i++){
        (*ppRes)[i]=(*pPreVec)[i];
        
    }
    
    printf(" ");
    for(i=aLen-1;i>=0;i--){
        printf("%d",a[i]);

    }
    printf(" X ");
    for(i=bLen-1;i>=0;i--){
        printf("%d",b[i]);

    }

    printf(" = \n ");

    
    for(i=iOutLen-1;i>=0;i--){
        printf("%d",(*ppRes)[i]);

    }

    printf("\n");

	return 0;
}

int itobytes10(int num,u_char *str)
{
    int i=0,j,k;
    char *tmpStr;
    unsigned unum;
    int outLen=0;

    tmpStr=(char *)str;

    if(num<0){
        unum=(unsigned)-num;
        str[i++]='-';
    }else{
        unum=(unsigned) num;
    }


    do{
       tmpStr[i++]=(unum%10);
       unum/=10;     

    }while(unum);

    outLen=i;
    if(tmpStr[0]=='-')k=1;
    else k=0;

/*
    printf("atoi number %d  ",num);
    for(j=0;j<i;j++)
    {
        printf("%d",tmpStr[j]);
    }
    printf(" ");

    char temp;
    //printf("\n i is %d ,k is %d ",i,k);
    for(j=k;j<=(i-1)/2;j++){
        temp=tmpStr[j];
        tmpStr[j]=tmpStr[i-1+k-j];
        tmpStr[i-1+k-j]=temp;

    }


    for(j=0;j<i;j++)
    {
        printf("%d",tmpStr[j]);
    }

    printf(" \n");
*/

    return outLen;

}

int multiply_test(int a,int b)
{
    u_char aStr[25];
    u_char bStr[25];
    u_char resStr[60];
    u_char *pRes=0;
    int i,outLen=0;
    int aLen=0,bLen=0,resLen=0;
    int normalRes=a*b;

    printf("c multiply: %d * %d = %d \n",a,b,normalRes);


    //itoa(a,aStr);

    //itoa(b,bStr);

    aLen=itobytes10(a,aStr);
    bLen=itobytes10(b,bStr);


    printf("aLen is %d \n",aLen);
    printf("bLen is %d \n",bLen);
    
    printf("\n a: ");
    for(i=aLen-1;i>=0;i--){
        printf("%d",aStr[i]);
    }
    printf(" b: ");
    for(i=bLen-1;i>=0;i--){
        printf("%d",bStr[i]);
    }

    printf("\n");

    multiply_bytes10(aStr,aLen,bStr,bLen,&pRes,&outLen);
    resLen=itobytes10(normalRes,resStr);

    if(resLen!=outLen){
        printf(" the result is not correct \n");
    }else{

        bool bSam=true;

        for(i=outLen-1;i>=0;i--){
           if(resStr[i]!=pRes[i]){
                printf("the result is not correct \n");
                bSam=false;
                break;
           } 

        }
        if(bSam) printf("the result is same \n");

    }
    
    printf("multiply_test end \n");
    if(*pRes!=0) free(pRes);

}

