#include "net.h"

int main(void){
	int fd, ret;
	struct sockaddr_in sin;  
	char buf[BUFSIZ];

	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {   
		perror("socket");
		exit(1);
	}

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;   
	sin.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, SERVER_IP, &sin.sin_addr);   
													
													
	if (bind(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {   
		perror("bind");
		exit(1);
	}

	while (1) {
		ret = recvfrom(fd, buf, BUFSIZ-1, 0, NULL, NULL);   
		if (ret < 0) {   
			perror("recvfrom");
			exit(1);
		}

		printf("from client: %s", buf);

		if (strncasecmp(buf, "quit", 4) == 0) {
			printf("client i is exiting.\n");
			//break;
		}
	}

	close(fd);

	return 0;
}
