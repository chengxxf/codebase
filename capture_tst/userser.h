#ifndef USER_SERVER_HHH
#define USER_SERVER_HHH


#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define TST_TCP_CONNECT 1


#define CLI_MSG_TYPE 1

#define DBG_FUNC(x) x##_debug_func


typedef struct BLOCK_HEAD_st
{
	unsigned short magic;
	unsigned short sSeqnu;

	union{
		unsigned char u1Type[4];
		unsigned int u4Type;

	}U_Type;

	unsigned int uDataLen;
	unsigned int uReserve1;
	unsigned int uReserve2;
	unsigned int uReserve3;
#define BLOCKHEAD_SIZE 24


}s_BLOCK_HEAD;

#define ADD_HDR_LEN(x) (x+BLOCKHEAD_SIZE)

class UserServer
{

public:
	UserServer();


	void incHdrMismatch(){_hdrMismatch++;if(!_bHdrPreHit){_hdrMisCont++;}else _hdrMisCont=0; }
	void resetHdrMismatch(){_hdrMismatch=0;}
	int getHdrMismatch(){return _hdrMismatch;}
	int getHdrMisCont(){return _hdrMisCont;}

	static void *UserSerMain(void *arg);

protected:

	void sendAck();
	void setAcceptFD(int fd);
#ifdef USER_SER_DBG
	void DBG_FUNC(DealCliMsg)(char *buf,int len,char *des="no des");
#else
	void DealCliMsg(char *buf,int len);
#endif

private:
	int DealRcvData(char * buf,int len);
	
	int _acceptFD;

	int _hdrMismatch;
	int _hdrMisCont;
	bool _bHdrPreHit;
	
	






};
#endif
