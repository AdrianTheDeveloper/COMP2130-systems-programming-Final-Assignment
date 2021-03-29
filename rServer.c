//620043175
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

	char * const gnum = "     A    B    C    D    E   F    G     H   I \n";

	char * const hori = "  .____.____.____.____.____.____.____.____.____.";
        char * const vert = "  |    |    |    |    |    |    |    |    |    |";
        char * grid[9][9];


void createGrid(){
        for(int i =0;i<9;i++){
                for(int j=0;j<9;j++){
                        grid[i][j]= "R";
                }//endfor
        }//endfor
}//end function


void displayGrid(){
	printf("%s", gnum);
        printf("%s\n", hori);
        for(int i =0;i<9;i++){
		printf("%d",i+1);
                for(int j=0;j<9;j++){
                        if(strcmp(grid[i][j]," ")==0){
                                printf(" | %s ",grid[i][j]);
                        }else{
                                printf(" | %s ",grid[i][j]);
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
void saveWorksheet( ){}//end function

void main(){
	createGrid();
        displayGrid();

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
	
		//accept incoming connection
	addrSize = sizeof(recvAddr);
	sockRecv = accept(sock, (struct sockaddr *) &recvAddr, &addrSize );
}//end main
