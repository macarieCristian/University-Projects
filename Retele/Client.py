'''
Created on Oct 11, 2017

@author: Cristian
'''
import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)  
s.sendto(b"Macarie Cristian",("172.30.3.3",5555))                 
print(s.recvfrom(10))