#ifndef _NET_H_
#define _NET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define SERVER_IP "192.168.31.200"   //xxx ""  
#define SERVER_PORT 10000
#define BACKLOG 2


/*
struct sockaddr_in {
	u_short sin_family;
	u_short sin_port;
	struct addr_in sin_addr;
	char sin_zero[6];
}
*/

#endif
