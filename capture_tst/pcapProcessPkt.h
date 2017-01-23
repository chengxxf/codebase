#ifndef PCAP_PROCESS_PKT_HH
#define PCAP_PROCESS_PKT_HH
#include "processPktAbs.h"

#include <pcap.h>
#include "eth.h"
#include <list>
#include <pthread.h>
#define TCP_LEV 4
#define IP_LEV  3
#define MAC_LEV 2
typedef struct ST_PCAP_OBSERVER
{
	int obsvrId;

	int needLevl;
	
	int dstPort;
	int srcPort;

	int dstIp;
	int srcIp;

	char dstMac[6];
	char srcMac[6];

}S_PCAP_OBSERVER;
//void processPacket(u_char *arg,const struct pcap_pkthdr * pkthdr,const u_char *packet)

class PcapProcessPkt:public ProcessPktAbs
{
public:

	static void(* m_processPkt)(u_char *,const struct pcap_pkthdr * ,const u_char *);
	PcapProcessPkt();



	void initProcessPkt();

	static  void selfProcessPkt(u_char *,const struct pcap_pkthdr * ,const u_char *);
	
	void lockObserver();
	void unlockObserver();

private:
	static PcapProcessPkt * s_pSelfObj;


	pthread_mutex_t _mutex;
	std::list<S_PCAP_OBSERVER *> m_observerList;


	




};
#endif
