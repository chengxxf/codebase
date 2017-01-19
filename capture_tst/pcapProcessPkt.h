#ifndef PCAP_PROCESS_PKT_HH
#define PCAP_PROCESS_PKT_HH
#include "processPktAbs.h"

#include <pcap.h>
//void processPacket(u_char *arg,const struct pcap_pkthdr * pkthdr,const u_char *packet)

class PcapProcessPkt:public ProcessPktAbs
{
public:

	static void(* m_processPkt)(u_char *,const struct pcap_pkthdr * ,const u_char *);
	PcapProcessPkt();




	virtual void selfProcessPkt(u_char *,const struct pcap_pkthdr * ,const u_char *);













};
#endif
