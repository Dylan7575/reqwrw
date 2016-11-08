#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <errno.h>

#include <resolv.h>
#include <arpa/inet.h>//for pton function


#define SERVER_NAME "131.107.13.100"//server address port number and otm char defined in constants
#define PORT_NUM 13
#define OTM_CHAR '*'