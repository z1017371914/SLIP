#ifndef CLIENT_H
#define CLIENT_H
void initSocket(char * ipAddress,int po);
void sendMessage(char * sendbuf,int length);
int recvMessage(char* recvbuf,int maxdata);
void destroy();
#endif
