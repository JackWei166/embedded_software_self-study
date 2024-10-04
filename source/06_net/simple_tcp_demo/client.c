#include "net.h"

int main(void){
	int fd, ret;
	struct sockaddr_in sin;  
	char buf[BUFSIZ];

	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {   
		perror("socket");
		return 1;
	}

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, SERVER_IP, &sin.sin_addr);   
	if (connect(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {   
		perror("connect");
		return 1;
	}

	while (1) {

		if (fgets(buf, BUFSIZ-1, stdin) == NULL) {   //xxx why -1
			continue;   //xxx input fail, can continue
		}

		do {
			ret = write(fd, buf, BUFSIZ-1);   
		} while(ret < 0 && errno == EINTR);   

		if (strncasecmp(buf, "quit", 4) == 0) {
			printf("client is exiting.\n");
			break;
		}
	}

	close(fd);

	return 0;
}
