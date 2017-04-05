#include <stdio.h>
#include "cast_oper.h"

#define UINT4 unsigned int
#define UINT2 unsigned short 

#define FLAVG(FrmLossValue,FrmLossValueAvg,u2NoOfLMRRcvd) \
do\
{\
    FrmLossValueAvg = (((FrmLossValueAvg * u2NoOfLMRRcvd) + FrmLossValue)/(u2NoOfLMRRcvd + 1));\
}while(0);


#define NEFLAVG(FrmLossValue,FrmLossValueAvg,u2NoOfLMRRcvd) \
do\
{\
        FLAVG(FrmLossValue,FrmLossValueAvg,u2NoOfLMRRcvd) \
}while(0);


#define FLAVG(FrmLossValue,FrmLossValueAvg,u2NoOfLMRRcvd) \
do\
{\
    FrmLossValueAvg = (((FrmLossValueAvg * u2NoOfLMRRcvd) + FrmLossValue)/(u2NoOfLMRRcvd + 1));\
}while(0);


#define NEFLAVG(FrmLossValue,FrmLossValueAvg,u2NoOfLMRRcvd) \
do\
{\
        FLAVG(FrmLossValue,FrmLossValueAvg,u2NoOfLMRRcvd) \
}while(0);

int test_u4()
{

    
    UINT4 FrmLossValueAvg=0;
    double dbFrmLossValueAvg=0.0;
    UINT2 u2NoOfLMRRcvd=2;
    UINT4 FrmLossValue=0;
    
    NEFLAVG(FrmLossValue,FrmLossValueAvg,u2NoOfLMRRcvd-1);
    printf("test %d   %u \n",__LINE__,FrmLossValueAvg);

    unsigned int a=-1;
    int b=0;

    int c=2;

    printf("a+b %u  %d \n",a+b,(a+b));
    printf("a+b/2 %u %d \n",(a+b)/2,(a+b)/2);

    printf(" -1/2 = %u \n ",-1/2);
    printf(" -1/c = %u \n ",-1/c);
    printf(" a/c = %u \n ",a/c);
    
    //frmLossValueAvg=(((frmLossValueAvg*u2NoOfLMRRcvd)+frmLossValue)/(u2NoOfLMRRcvd+1));

    FrmLossValueAvg=0;
    FrmLossValueAvg = ((((UINT4)(0 * 2-1)) + 2)/(2-1 + 1));
    printf("test %d (((0 * 2-1) + 0)/(2-1 + 1))= %u \n",__LINE__,FrmLossValueAvg);

    FrmLossValueAvg=0;
    FrmLossValueAvg = (((FrmLossValueAvg * 2-1) + -1)/(2-1 + 1));
    printf("test %d (((FrmLossValueAvg * 2-1) + 0)/(2-1 + 1))=  %u \n",__LINE__,FrmLossValueAvg);

    FrmLossValueAvg=0;
    FrmLossValueAvg = (((FrmLossValueAvg * u2NoOfLMRRcvd-1) + 0)/(2-1 + 1));
    printf("test %d (((FrmLossValueAvg * 2-1) + 0)/(2-1 + 1))=  %u \n",__LINE__,FrmLossValueAvg);

    FrmLossValueAvg=0;
    FrmLossValueAvg=(((FrmLossValueAvg * u2NoOfLMRRcvd-1) + 0)/(2-1 + 1));
    printf("test %d   %u \n",__LINE__,FrmLossValueAvg);

    FrmLossValueAvg=0;
    FLAVG(0,FrmLossValueAvg,2-1);
    printf("test %d   %u \n",__LINE__,FrmLossValueAvg);

    FrmLossValueAvg=0;
    NEFLAVG(0,FrmLossValueAvg,2-1);
    printf("test %d   %u \n",__LINE__,FrmLossValueAvg);

    FrmLossValue=99;
    dbFrmLossValueAvg=FrmLossValue;

    int period1=474;
    int end=635;
    int i=0;
    for(i=u2NoOfLMRRcvd;i<period1;i++,u2NoOfLMRRcvd++)
    {
        FrmLossValue=99;
        NEFLAVG(FrmLossValue,dbFrmLossValueAvg,(u2NoOfLMRRcvd-1));
        printf("%d : %f \n",i,dbFrmLossValueAvg);

    }
    printf("period 1-------------%f : %u \n",i-1,dbFrmLossValueAvg);

    for(i=period1;i<end;i++,u2NoOfLMRRcvd++)
    {
        FrmLossValue=0;
        NEFLAVG(FrmLossValue,dbFrmLossValueAvg,(u2NoOfLMRRcvd-1));
        if(i==594){
            printf("view the value---  %d : %f \n",i,dbFrmLossValueAvg);
        }
        printf("%d : %f \n",i,dbFrmLossValueAvg);

    }

    
















    return 0;
}
