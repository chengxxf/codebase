#!/usr/bin/python

import struct
from socket import *
HOST = 'localhost'
PORT = 20000
ip_port=(HOST,PORT)

if __name__=='__main__':
	sk=socket(AF_INET,SOCK_STREAM)
	sk.bind(ip_port)
	sk.listen(5)
	while True:
		print ('server waiting .. ')
		conn,addr=sk.accept()

		client_data=conn.recv(1024)


		conn.sendall(bytes('not answver'))
		conn.close()


