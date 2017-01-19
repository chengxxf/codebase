#include "pcapRx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "pcapProcessPkt.h"

PcapRx::PcapRx()
{
	strncpy(dev,DEFAULT_DEV,DEVNAMEMAX);
	memset(errbuf,0,PCAP_ERRBUF_SIZE);
	_handle=0;
	_hasInit=0;
}

PcapRx::~PcapRx()
{

		
}


int PcapRx::init()
{
	printf("call %s %s \n",__FUNCTION__,dev);
	if(pcap_lookupnet(dev,&net,&mask,errbuf)==-1){
		fprintf(stderr,"Can't get netmask for device %s\n",dev);
		net=0;
		mask=0;
	}	

	//device=pcap_lookupdev(errbuf);
	
	_handle=pcap_open_live(dev,MAXBYTE2CAPTURE,1,1000,errbuf);

	printf("%s %d \n",__FUNCTION__,__LINE__);

	if(!_handle){
		std::cout <<"open device fail "<<errbuf<<std::endl;
		return 2;

	}
	if(pcap_activate(_handle)){
		std::cout <<"Activated!"<<std::endl;
	}
	printf("%s %d \n",__FUNCTION__,__LINE__);
	if(_handle==NULL){
		fprintf(stderr,"Couldn't open device %s : %s \n",dev,errbuf);
		return (2);
	}
	printf("%s %d \n",__FUNCTION__,__LINE__);
	
	if(pcap_compile(_handle,&fp,filter_exp,0,net)==-1){
		fprintf(stderr,"Coundn't parse filter %s: %s \n",filter_exp,pcap_geterr(_handle));
		return 2;

	}
	printf("%s %d \n",__FUNCTION__,__LINE__);

	if(pcap_setfilter(_handle,&fp)==-1){
		fprintf(stderr,"Coundn't install filter %s: %s \n",filter_exp,pcap_geterr(_handle));
		return 2;
		
	}
	printf("%s %d \n",__FUNCTION__,__LINE__);

	_hasInit=1;

	return 0;

}

void PcapRx::RxLoop()
{
	printf("call %s \n",__FUNCTION__);
	if(1!=_hasInit){
		std::cout <<" has not init  "<<std::endl;
	 	return ;
	}

	pcap_dispatch(_handle,5,PcapProcessPkt::m_processPkt,0);
	pcap_loop(_handle,0,PcapProcessPkt::m_processPkt,0);
	pcap_close(_handle);

}
