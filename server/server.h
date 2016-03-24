#ifndef SERVER_H
#define SEREVR_H
void initServer(int port);
void sendServer(char * sendbuf);
int recvServer(char* recvbuf,int maxdata);
void destroyServer();
#endif

