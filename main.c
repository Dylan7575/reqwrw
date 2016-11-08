#include <arpa/inet.h>
#include "Header.h"

char* read_line(int socket);
char* daytime_connect();
char* get_part(char* part,char*type);int main(int argc, char** argv);
int main(int argc,char** argv){
	int server_socket;                 // descriptor of server socket
	struct sockaddr_in server_address; // for naming the server's listening socket
	int client_socket;

	// create unnamed network socket for server to listen on
	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Error creating socket");
		exit(EXIT_FAILURE);
	}

	// name the socket (making sure the correct network byte ordering is observed)
	server_address.sin_family      = AF_INET;           // accept IP addresses
	server_address.sin_addr.s_addr = htonl(INADDR_ANY); // accept clients on any interface
	server_address.sin_port        = htons(23670);       // port to listen on

	// binding unnamed socket to a particular port
	if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
		perror("Error binding socket");
		exit(EXIT_FAILURE);
	}

	// listen for client connections (pending connections get put into a queue)
	if (listen(server_socket, 1) == -1) {
		perror("Error listening on socket");
		exit(EXIT_FAILURE);
	}


		//locking mutex so the server doesnt jump into the next client to fast
	//	pthread_mutex_lock(&lock);
		if ((client_socket = accept(server_socket, NULL, NULL)) == -1) {
			perror("Error accepting client");
		}
		else {
			printf("Accepted client\n");
			char* temp =daytime_connect();
			temp =get_part(temp,"Year");
			printf("%s",temp);

			}
		}


char* read_line(int socket){
	int counter=0; //for going through buffer array
	char* buffer=malloc(80* sizeof(char)); // mallocing an array to keep variable saved
	while((read(socket,&buffer[counter],1))>0){//reading in the stream byte by byte so to catch the otm character
		if(buffer[counter]== OTM_CHAR){//if the character is the OTM char go back one char and null terminate and break loop
			buffer[counter-1]='\0';
			break;
		}
		counter++;//incrementing array

	}
	return buffer;//returning full string
}
char* daytime_connect(){
	int sock;
	struct sockaddr_in dest;
	if((sock=socket(AF_INET,SOCK_STREAM,0))==-1){//creating socket and error checking
		perror("Socket has malfuncioned");
		exit(-1);
	}
	dest.sin_family=AF_INET;
	dest.sin_port= htons(PORT_NUM);

	if ( inet_pton(AF_INET,SERVER_NAME,&dest.sin_addr) < 0 )//assigning address to socket
	{
		perror("");
		exit(errno);
	}
	if(connect(sock,(struct sockaddr*)&dest, sizeof(dest))!=0){//connecting local socket to dest socket and error checking
		perror("Error Connecting");
		exit(0);
	}
	char* temp =read_line(sock);  //sending sending socket to be read and printing results

	close(sock);//closing the socket
	return temp;
}
char* get_part(char* part,char* type){
	int breaks=-1;
	int i=0;
	if(type=="Year"){
		breaks=1;
	}
	while(breaks!=0){
		char temp = part[i++];
		if(temp == ' '||temp == '-'|| temp ==':'){
			breaks-=1;
		}
	}
	char* val=malloc(sizeof(char)*2);
	val[0]=part[i];
	val[1]=part[i+1];
	return val;



}
