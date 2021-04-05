//620043175
//620118713
//620107205


#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

//create grid structure to save cell name and value

 struct Grid {
	char cell[30];
        char value[30];
};//end struct


	char * const gnum = "     A    B    C    D    E   F    G     H   I \n";

	char * const hori = "  .____.____.____.____.____.____.____.____.____.";
        char * const vert = "  |    |    |    |    |    |    |    |    |    |";
        //char * grid[9][9];
	struct Grid grid[9][9];

void createGrid(){
	int i=0;
	int j=0;
	char x[] = "A";
	char cname[2];
        for( i =0;i<9;i++){
		x[0]=x[0]+i;
                for( j=0;j<9;j++){
			strcat(cname,x);
			char *z;
			sprintf(z, "%d", j+1);
		       	strcat(cname,z);                        
			strcat(grid[i][j].cell, cname);
			printf("%s\n",grid[i][j].cell);
                }//endfor
        }//endfor
}//end function


void displayGrid(){
	printf("%s", gnum);
        printf("%s\n", hori);
        for(int i =0;i<9;i++){
		printf("%d",i+1);
                for(int j=0;j<9;j++){
                        if(strcmp(grid[i][j].value," ")==0){
                                printf(" | %s ",grid[i][j].value);
                        }else{
                                printf(" | %s ",grid[i][j].value);
                        }
                }//endfor
                printf(" |\n");
                printf("%s \n",vert);
                printf("%s \n",hori);
        }//endfor
}//end function


/*server functions*/
//save current spreadsheet from memory to a location on the file system running server
//save in amy format
//only first client shoult be able to save
void saveWorksheet( ){

}//end function

/*create threads*/
pthread_t tid[3];
int tc;
pthread_mutex_t lock;
void* conn(void *args);

void main(){
	//createGrid();
        //displayGrid();
	int k;
	int p = 0;
	                //create socket
        int i,sock,sockRecv, addrSize;
        struct sockaddr_in myAddr;
        struct sockaddr_in recvAddr;
        unsigned short listenPort = 6000;

        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sock<0)
                printf("socket() failed\n");
                exit(9);
        //return 0;

                //make local address structure
        memset(&myAddr, 0, sizeof(myAddr)); //clr structure
        myAddr.sin_family = AF_INET; //address family
        myAddr.sin_addr.s_addr = htonl(INADDR_ANY); // my ip address
        myAddr.sin_port = htons(listenPort);

                //bind socket to address
        i = bind(sock, (struct sockaddr *) &myAddr, sizeof(myAddr));
        if(i<0)
                printf("bind() failed\n");
        
	//listen for connection
        i = listen(sock, 5);
        if(i<0)
                printf("listen() failed");
	

	while(p<3){
	//accept incoming connection
        addrSize = sizeof(recvAddr);
        sockRecv = accept(sock, (struct sockaddr *) &recvAddr, &addrSize);


		/* thread here*/
	if(pthread_mutex_init(&lock,NULL)!=0)
		printf("failed to initialized mutex");
		
       	//for(int j=0;j<3;j++){
		k = pthread_create(&(tid[p]),NULL,&conn, NULL);
		if(k!=0)
			printf("cannot create thread");
	//}//end for
	pthread_join(tid[p],NULL);
	//pthread_join(tid[1],NULL);
	//pthread_join(tid[2],NULL);
	p+=1;
	pthread_mutex_destroy(&lock);
	}
}//end main


void* conn(void *arg){
	int recvr, sndr;
	char text[] = "please enter input";
	char mess[80];	
	pthread_mutex_lock(&lock);
	tc+=1;
	printf("connect %d made \n",tc);
	sndr = send(sndr, text, strlen(text), 0 );
  	recvr  = recv(recvr, mess, 80, 0);

	//send message to client to ask for inpiut
	
	//close connection
	
	pthread_mutex_unlock(&lock);
}
