#include "pktRxFactory.h"
#include "pcapRx.h"


PktRxFactory::PktRxFactory()
{


}


AbstractRx *PktRxFactory::createPktRx()
{
	AbstractRx *pNewRx=0;

	pNewRx=new PcapRx();
	
	return pNewRx;
}
