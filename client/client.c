#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> /* netbd.h is needed for struct hostent =) */
#include "client.h"
//#define PORT 1234 /* Open Port on Remote Host */
/* Max number of bytes of data */

static int fd;/* files descriptors */


static struct hostent *he; /* structure that will get information about remote host */
static struct sockaddr_in server; /* server's address information */
static  socklen_t len;
static int port;
void initSocket(char * ipAddress,int po)
{
	port=po;
	if ((he=gethostbyname(ipAddress))==NULL){ /* calls gethostbyname() */
	printf("gethostbyname() error\n");
	exit(1);
	}

	if ((fd=socket(AF_INET, SOCK_DGRAM, 0))==-1){ /* calls socket() */
	printf("socket() error\n");
	exit(1);
	}

	bzero(&server,sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(port); /* htons() is needed again */
	server.sin_addr = *((struct in_addr *)he->h_addr); /*he->h_addr passes "*he"'s info to "h_addr" */
	 len=sizeof(struct sockaddr_in);
}
void sendMessage(char * sendbuf,int length){
	sendto(fd,sendbuf,length,0,(struct sockaddr *)&server,len);
}
int recvMessage(char* recvbuf,int maxdata){
    int num;
    num=recvfrom(fd,recvbuf,maxdata,0,(struct sockaddr *)&server,&len);
    return num;
}
void destroy()
{
	close(fd);
}
