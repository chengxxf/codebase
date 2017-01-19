#include "pcapProcessPkt.h"
#include <ctype.h>


void fakeProcessPkt(u_char * arg,const void * pkt ,const u_char *arg2)
{
	printf("This is pcap fake Process Pkt callback\n");
}

void (*PcapProcessPkt::m_processPkt)(u_char *,const struct pcap_pkthdr * ,const u_char *)
	=(void (*)(u_char *,const struct pcap_pkthdr * ,const u_char *))&fakeProcessPkt;
PcapProcessPkt::PcapProcessPkt()
{


}

void PcapProcessPkt::selfProcessPkt(u_char *arg,const struct pcap_pkthdr * pkthdr,const u_char *packet)
{

	int i;
	fprintf(stdout,"Pcap Received Packet Size: %d \n",pkthdr->len);

	return ;
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



}
