//620043175
//620118713
//620107205
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


#define BUF_SIZE	1024
#define	SERVER_IP	"127.0.0.1"
#define SERVER_PORT	6000

int main(int argc, char *argv[]){
    int	i, p, sock, sendData,sent;
    struct sockaddr_in	sendAddr;
    char buf[BUF_SIZE];

        //create socket 
    sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0){
        printf("socket() failed\n");
        exit(0);
    }

        //create local address structure 
    memset(&sendAddr, 0, sizeof (sendAddr)); //clr structure 
    sendAddr.sin_family = AF_INET; //address family 
    sendAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    sendAddr.sin_port = htons((unsigned short)SERVER_PORT);

        //connect to the server
    if(connect(sock, (struct sockaddr *) &sendAddr, sizeof (sendAddr))<0){
        printf("connecting\n");
        exit(0);
    }

    while (1){
        //send data
        sent=sizeof(sendAddr);
        sendData=send(sock,buf,p,0);
        printf("%d\n",p);
    }

    close(sock);
}


