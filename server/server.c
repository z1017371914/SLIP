#include <stdio.h> /* These are the usual header files */
#include <string.h>
#include <unistd.h> /* for close() */
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"
static int sockfd; /* socket descriptors */
static struct sockaddr_in server; /* server's address information */
static struct sockaddr_in client; /* client's address information */
static socklen_t sin_size;
void initServer(int port){
	/* Creating UDP socket */
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		/* handle exception */
		perror("Creating socket failed.");
		exit(1);
	}

	bzero(&server,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	server.sin_addr.s_addr = htonl (INADDR_ANY);
	if (bind(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
	/* handle exception */
	perror("Bind error.");
	exit(1);
	}

	sin_size=sizeof(struct sockaddr_in);
}

////从client中获取值 并或得client的ip地址
int recvServer(char* recvbuf,int maxdata){
	int num;
	num = recvfrom(sockfd,recvbuf,maxdata,0,(struct sockaddr *)&client,&sin_size);
	return num;
}

void sendServer(char * sendbuf){
	sendto(sockfd,sendmsg,strlen(sendmsg),0,(struct sockaddr *)&client,sin_size);
}

void destroyServer(){
	close(sockfd);
}



