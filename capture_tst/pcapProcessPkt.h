#ifndef PCAP_PROCESS_PKT_HH
#define PCAP_PROCESS_PKT_HH
#include "processPktAbs.h"

#include <pcap.h>
#include "eth.h"
#include <list>

typedef struct ST_PCAP_OBSERVER
{
	int obsvrId;

	int needLevl;
	
	


}S_PCAP_OBSERVER;
//void processPacket(u_char *arg,const struct pcap_pkthdr * pkthdr,const u_char *packet)

class PcapProcessPkt:public ProcessPktAbs
{
public:

	static void(* m_processPkt)(u_char *,const struct pcap_pkthdr * ,const u_char *);
	PcapProcessPkt();



	void initProcessPkt();

	static  void selfProcessPkt(u_char *,const struct pcap_pkthdr * ,const u_char *);


private:
	static PcapProcessPkt * s_pSelfObj;



	std::list<S_PCAP_OBSERVER *> m_observerList;







};
#endif
