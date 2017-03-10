#ifndef USER_SERVER_HHH
#define USER_SERVER_HHH


#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define TST_TCP_CONNECT 1


#define CLI_MSG_TYPE 1

typedef struct BLOCK_HEAD_st
{
	unsigned short magic;
	unsigned short sReserve1;

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


	void incHdrMismatch(){_hdrMismatch++;}
	void resetHdrMismatch(){_hdrMismatch=0;}
	int getHdrMismatch(){return _hdrMismatch;}

	static void *UserSerMain(void *arg);

protected:
	void DealCliMsg(char *buf,int len);


private:
	int DealRcvData(char * buf,int len);
	

	int _hdrMismatch;
	
	








};
#endif
