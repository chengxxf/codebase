#ifndef PCAPRX_HHH
#define PCAPRX_HHH 

#include "abstractRx.h"
#include <pcap.h>
#define DEVNAMEMAX 20
#define DEFAULT_DEV "eth0"
#define MAXBYTE2CAPTURE 2048

class PcapRx:public AbstractRx
{
public :
	PcapRx();
	virtual ~PcapRx();



	int init();
	void RxLoop();



private:

	pcap_t *_handle;
	char errbuf[PCAP_ERRBUF_SIZE];
	char dev[DEVNAMEMAX];


	struct bpf_program fp;
	char *filter_exp;
	bpf_u_int32 mask;
	bpf_u_int32 net;
	struct pcap_pkthdr header;
	const u_char *packet;

	int _hasInit;

};

#endif
