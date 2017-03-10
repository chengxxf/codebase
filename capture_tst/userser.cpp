#include "userser.h"
#include <iostream>
#include <stdio.h>
#include <errno.h>

#define USER_SER_PORT 20000
#define MAXSIZE 4096

UserServer::UserServer()
{
	_hdrMismatch=0;

}
	
void *UserServer::UserSerMain(void *arg)
{

	UserServer  curSer;

	int socket_fd=-1,accept_fd,listen_port;
	sockaddr_in myserver;
	sockaddr_in remote_addr;
	
	listen_port=USER_SER_PORT;

	printf("user sermain \n");
	fflush(stdout);
	if((socket_fd=socket(AF_INET,SOCK_STREAM,0)) < 0 ){

		printf("socket() failed %d \n",errno);
		return 0;
	}

	printf("socket_fd %d listen_port %d \n",socket_fd,listen_port);
	memset(&myserver,0,sizeof(myserver));

	myserver.sin_family=AF_INET;
	myserver.sin_addr.s_addr=htonl(INADDR_ANY);
	myserver.sin_port=htons(listen_port);
	
	printf("before bind\n");
	if(bind(socket_fd,(sockaddr *) &myserver,sizeof(myserver))<0){
		printf("bind() failed %d \n",errno);
		return 0;

	}else{
		printf("bind success\n");

	}
	
	printf("before listen\n");
	if(listen(socket_fd,10)<0){
		printf("listen() failed %d \n",errno);
		return 0;
	}else{

		printf("listen success\n");
	}


	printf("-------user server socket success start------\n");
	while(1){

		socklen_t sin_size=sizeof(struct sockaddr_in);
		printf("user server wait for connect \n");
		curSer.resetHdrMismatch();
		if((accept_fd=accept(socket_fd,(struct sockaddr *) &remote_addr,&sin_size))== -1 )
		{
			printf("Accept error!");
			continue;

		}

		
		printf("the accept fd is %d \n",accept_fd);
		printf("there is a new client arrive  \n");
		printf(" MAXSIZE　is %d \n",MAXSIZE);

		char buffer[MAXSIZE*2];
		
		memset(buffer,0,MAXSIZE*2);
	
		int byteCnt=0;
		int curLeft=0;
		while((byteCnt=read(accept_fd,buffer+curLeft,MAXSIZE-curLeft))>0){


			curLeft=curSer.DealRcvData(buffer,curLeft+byteCnt);
					
			
		}

		if(0==byteCnt)
		{
			printf("no bytes read errno is %d \n",errno);
		}
		else if(-1==byteCnt)
		{
			printf("read error \n");

		}
		
	

	
		
	}


}


void UserServer::DealCliMsg(char *buf,int len)
{


}


int UserServer::DealRcvData(char * buf,int len)
{

	printf("DealRcvData Entry \n");
	
	
	int left=0;//bytes not deal

	int offset=0;
	if(len<BLOCKHEAD_SIZE)
		return len;

	s_BLOCK_HEAD *hdr= (s_BLOCK_HEAD *)buf;


	if(hdr->magic!=ntohs(0xabcd)){
		printf("magic number don't match \n something is wrong ,drop the data\n");
		incHdrMismatch();
		
		if(getHdrMismatch()>=10){
			printf("header mismatch happen too many times \n");

		}
		
		
		return 0;

	}else{

		printf("magic nub matches \n");
	}

	if(ntohl(hdr->uDataLen)+BLOCKHEAD_SIZE>len){

		printf("the msg has data not received \n");
		return ntohl(hdr->uDataLen)+BLOCKHEAD_SIZE-len;
	}

	DealCliMsg(buf,BLOCKHEAD_SIZE+ntohl(hdr->uDataLen));

	left=len-(ntohl(hdr->uDataLen)+BLOCKHEAD_SIZE);
	offset=ntohl(hdr->uDataLen)+BLOCKHEAD_SIZE;

	while(left>BLOCKHEAD_SIZE){
		// deal the normal data 
		hdr= (s_BLOCK_HEAD *)(buf+offset);

		if(ntohl(hdr->uDataLen)+BLOCKHEAD_SIZE<=left){
			DealCliMsg(buf+offset,ADD_HDR_LEN(hdr->uDataLen));

			left=left-(ntohl(hdr->uDataLen)+BLOCKHEAD_SIZE);
			offset+=ADD_HDR_LEN(hdr->uDataLen);
		}else{
			// has a head but no enough data

			//left=ntohl(hdr->uDataLen)+BLOCKHEAD_SIZE-left;
			//copy data to begin 
			memcpy(buf,buf+offset,left);
			
			break;
		}

	}

	// has no header

	
	offset+=sizeof(s_BLOCK_HEAD);

	for(int i=0;i<offset;i++)
	{
		printf(" %02x ",(unsigned char)buf[i]);

	}

	for(int i=offset;i<len;i++)
	{
		printf("%c",buf[i]);

	}
	printf("\n");

	return left;
}




