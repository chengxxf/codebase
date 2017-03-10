#!/usr/bin/python

import struct
from socket import *
HOST = 'localhost'
PORT = 20000
BUFSIZE = 1024
ADDR = (HOST ,PORT)


class BlockHead:

	magic=0xabcd
	sReserve1=0;
	
	u1Type=bytearray([0,0,0,0]);
	u4Type=0;

	uLen=0;
	uReserve1=0;
	uReserve2=0;
	uReserve3=0;
	
	def __init__(self):
		print "blockHead"
		

class ConnectToSer:
	tcpClientSock=0	
	def connect(self):
		self.tcpClientSock = socket(AF_INET,SOCK_STREAM)
		self.tcpClientSock.connect(ADDR)

	def query(self):
		while True:
			data=raw_input('Enter a string your want to send >')
			if not data:
				break

# the format is BlockHead
			print len(data)
			print isinstance(data,str)
			format="!HH4B4I{0}s".format(len(data))
			print format

			mystring="hello pack"
			output=struct.pack("Hb3b4s",0,ord('I'),1,1,1,"ok")
			print output
	
			head=BlockHead()
			head.u1Type[0]=1
			
			testData="ok"
			head.uLen=len(data);
			str1=struct.pack(format,head.magic,head.sReserve1,head.u1Type[0],head.u1Type[1],head.u1Type[2],head.u1Type[3],
				head.uLen,head.uReserve1,head.uReserve2,head.uReserve3,data)

			print str1
			print repr(str1)
			self.tcpClientSock.send(str1)
			data=self.tcpClientSock.recv(BUFSIZE)

			if not data:
				break
			print data


	def close(self):
		self.tcpClientSock.close()
		

	def doit(self):
		connect();
		query();
		close();	

if __name__ == '__main__' :
	print "begin to con"
	
	con=ConnectToSer()
	con.connect()

	con.query()

	con.close()

