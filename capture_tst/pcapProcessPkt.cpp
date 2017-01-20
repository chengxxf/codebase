#include "pcapProcessPkt.h"
#include <ctype.h>


void fakeProcessPkt(u_char * arg,const void * pkt ,const u_char *arg2)
{
	printf("This is pcap fake Process Pkt callback\n");
}

//void (*PcapProcessPkt::m_processPkt)(u_char *,const struct pcap_pkthdr * ,const u_char *)
//	=(void (*)(u_char *,const struct pcap_pkthdr * ,const u_char *))fakeProcessPkt;
void (*PcapProcessPkt::m_processPkt)(u_char *,const struct pcap_pkthdr * ,const u_char *)
	=&PcapProcessPkt::selfProcessPkt;

PcapProcessPkt* PcapProcessPkt::s_pSelfObj=0;
PcapProcessPkt::PcapProcessPkt()
{


}
void PcapProcessPkt::initProcessPkt()
{

	//m_processPkt=selfProcessPkt;
	s_pSelfObj=this;
}

void PcapProcessPkt::selfProcessPkt(u_char *arg,const struct pcap_pkthdr * pkthdr,const u_char *packet)
{

	int i;
	fprintf(stdout,"Pcap Received Packet  \n");

	const struct sniff_ethernet *ethernet ;
	const struct sniff_ip *ip;
	const struct sniff_tcp *tcp;
	const u_char *payload;

	u_int size_ip;
	u_int size_tcp;
	
	ethernet = (struct sniff_ethernet *) (packet);
	ip=(struct sniff_ip *)(packet+SIZE_ETHERNET);
	size_ip=IP_HL(ip)*4;
	if(size_ip <12) {
		printf(" * Invalid Tcp Header length : % u bytes \n",size_tcp);
		return;

	}
	
	payload=(u_char *)(packet + SIZE_ETHERNET + size_tcp);


	return ;

/*
	for(i=0;i<pkthdr->len;i++)
	{
		if(isprint(packet[i]))
			fprintf(stdout,"%c ",packet[i]);
		else
			fprintf(stdout,". ");

		if((i%16==0 && i!=0) || i==pkthdr->len-1)
			printf("\n");
	}

	return;

*/

}
