'''
Created on Oct 11, 2017

@author: Cristian
'''

#import socket
#s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)  
#s.bind(("0.0.0.0",5550))                           
#a1,addr=s.recvfrom(10)
#a2=s.recvfrom(10)[0]     
#a1=int(a1)
#a2=int(a2)
#a1+=a2
#a1=str(a1)
#b=bytes(a1,'utf-8')
#s.sendto(b" sarmale", addr)
#s.sendto(b, addr)
#print(a1)



import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)  
s.bind(("0.0.0.0",8888))
while(1):                           
    buff,addr=s.recvfrom(200)                           
    print(buff)
    a=input("Message: ")
    b=bytes(a,'utf-8')
    s.sendto(b, addr)     