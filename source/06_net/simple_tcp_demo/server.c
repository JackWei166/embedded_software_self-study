#include "net.h"

int main(void){
	int fd, newfd, ret;
	struct sockaddr_in sin;  //xxx sockaddr_in socketaddr_in
	char buf[BUFSIZ];

	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {   //xxx SOCK_STREAM SOCKET_STREAM
														//xxx can setsockopt
														//reuse = 1
		perror("socket");
		return 1;
	}

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;   //xxx 绑定、转换一般都用af，af比pf用的也比较广泛
	sin.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, SERVER_IP, &sin.sin_addr);   //xxx inet_pton 不是pton!!!  失败可能不是-1暂不管。 了解下有必要每个函数调用都判错吗？
													//xxx INADDY_ANY any net
													//card if only tpc
	if (bind(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {   //xxx sin别忘转类型
		perror("bind");
		return 1;
	}

	if (listen(fd, BACKLOG) < 0) {
		perror("listen");
		return 1;
	}

	if ((newfd = accept(fd, NULL, NULL)) < 0) {   //xxx NULL NULL client ip port =struct sockaddr_in struct sockaddr
		perror("accept");
		return 1;
	}

	while (1) {
		do {
			ret = read(newfd, buf, BUFSIZ-1);   //xxx 为什么减一来着？;socket pipe etc read write like
		} while(ret < 0 && errno == EINTR);   //xxx EINTR什么意思来着？哦，就是中断了，其他状态没有改变，所以可以重试。
		if (ret < 0) {   //xxx 对，每个错误处理 应该根据ret的不同情况进行处理 之前粗糙了；小于0 两种情况，等于0 一种，大于0 一种；write也是这样分析处理
			perror("read");
			return 1;
		}
		if (ret == 0) {
			printf("server is exiting.\n");   //xxx 哦，从一个文件到一个文件，newfd stdout 一般用到buf缓存
			return 0;
		}

		printf("from client: %s", buf);

		if (strncasecmp(buf, "quit", 4) == 0) {
			printf("server is exiting.\n");
			break;
		}
	}

	close(fd);
	close(newfd);

	return 0;
}
