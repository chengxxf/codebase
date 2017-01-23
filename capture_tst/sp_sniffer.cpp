//sp_sniffer.cpp

#include <string.h>
#include <stdlib.h>
#include <pcap.h>
#include <ctype.h>
#include <iostream>
#include <pthread.h>
#include "pktRxFactory.h"
#include "abstractRx.h"

#define MAXBYTE2CAPTURE 2048

typedef struct THREAD_ARG
{
	pcap_t *handle;

}S_THREAD_ARG;

void processPacket(u_char *arg,const struct pcap_pkthdr * pkthdr,const u_char *packet)
{

	return;

}

int g_mainLoop=1;
pthread_t tid_cap;
S_THREAD_ARG cap_arg;

# define weak_alias(name, aliasname) _weak_alias (name, aliasname)
# define _weak_alias(name, aliasname) \
  extern __typeof (name) aliasname __attribute__ ((weak, alias (#name)));

extern "C" {
void shutdown_main() __attribute__((weak));

void _socket_1();
void alias_shutdown_main() __attribute__((alias("shutdown_main")));
void shutdown_main() 
{
	g_mainLoop=0;
}

weak_alias(_socket_1,socket_1)
void _socket_1(){}
}

void *capture_pkt(void *arg)
{

	S_THREAD_ARG *thArg=(S_THREAD_ARG *)arg;
	pcap_t *handle=thArg->handle;
	PktRxFactory rxFactory;
	
	AbstractRx *pRx=rxFactory.createPktRx();
	if(!pRx)
	{
		std::cerr<<"create rx packect object err"<<std::endl;
		return 0;

	}
	if(0!=pRx->init())
	{
		std::cerr<<"rx packet init err"<<std::endl;
	}
	pRx->RxLoop();

	delete pRx;

	shutdown_main();
}


int main(int argc,char *argv[])
{	
/*
	int i=0,count=0;
	pcap_t *handle=NULL;
	char errbuf[PCAP_ERRBUF_SIZE],dev[]="eth0";
	struct bpf_program fp;
	char filter_exp[] = "tcp ";
	bpf_u_int32 mask;
	bpf_u_int32 net;
	struct pcap_pkthdr header;
	const u_char *packet;

	memset(&cap_arg,0,sizeof(cap_arg));
	memset(errbuf,0,PCAP_ERRBUF_SIZE);
	memset(&header,0,sizeof(header));
	printf("sniffer---------------\n");
	
	if(pcap_lookupnet(dev,&net,&mask,errbuf)==-1){
		fprintf(stderr,"Can't get netmask for device %s\n",dev);
		net=0;
		mask=0;
	}	

	//device=pcap_lookupdev(errbuf);
	
	handle=pcap_open_live(dev,MAXBYTE2CAPTURE,1,1000,errbuf);

	if(pcap_activate(handle)){
		std::cout <<"Activated!"<<std::endl;
	}
	if(handle==NULL){
		fprintf(stderr,"Couldn't open device %s : %s \n",dev,errbuf);
		return (2);
	}
	
	if(pcap_compile(handle,&fp,filter_exp,0,net)==-1){
		fprintf(stderr,"Coundn't parse filter %s: %s \n",filter_exp,pcap_geterr(handle));
		return 2;

	}

	if(pcap_setfilter(handle,&fp)==-1){
		fprintf(stderr,"Coundn't install filter %s: %s \n",filter_exp,pcap_geterr(handle));
		return 2;
		
	}

*/

	int err;
	cap_arg.handle=0;
	err=pthread_create(&(tid_cap),0,&capture_pkt,&cap_arg);
	
	if(err!=0)
		printf(" can't create thread \n");
	while(g_mainLoop)
	{
		sleep(2);
	}


	return 0;
}





