#include "net.h"

int main(void){
	int fd;
	struct sockaddr_in sin;  
	char buf[BUFSIZ];

	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {   
		perror("socket");
		return 1;
	}

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, SERVER_IP, &sin.sin_addr);   

	while (1) {
		if (fgets(buf, BUFSIZ-1, stdin) == NULL) {
			continue;
		}

		sendto(fd, buf, BUFSIZ-1, 0, (struct sockaddr *)&sin, sizeof(sin));   

		if (strncasecmp(buf, "quit", 4) == 0) {
			printf("client is exiting.\n");
			break;
		}
	}

	close(fd);

	return 0;
}
