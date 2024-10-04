#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define N 64
#define TypeA 1   //xxx 是不能为0，还是gpt靠谱，比kimi 豆包
#define TypeB 2

typedef struct {
	long mtype;
	char mtext[N];
} MSG;

#define LEN (sizeof(MSG) - sizeof(long))

int main(void){
	key_t key;
	int msgid;
	MSG buf;

	if ((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		return 1;
	}

	if ((msgid = msgget(key, 0666 | IPC_CREAT)) < 0) {
		perror("msgget");
		return 1;
	}

	while (1) {
		buf.mtype = TypeB;
		fgets(buf.mtext, N, stdin);
		msgsnd(msgid, &buf, LEN, 0);   //xxx 对，snt(snd!!!)要有长度和阻塞与否的确定，发送到队列 队列满了呢
		if (strcmp(buf.mtext, "quit\n") == 0) break;

		if (msgrcv(msgid, &buf, LEN, TypeA, 0) < 0) {   //xxx 也要长度和阻塞与否，接收队列 队列可能空 可能没有自己想要的
			perror("msgrcv"); //xxx 给别人 别人名字；拿自己的，自己名字
			msgctl(msgid, IPC_RMID, NULL);   //xxx 接收失败，不删msgid，另一个程序还运行；手动关闭，那msgid怎么办呢？系统回收吗？
			return 1;
		}
		if (strcmp(buf.mtext, "quit\n") == 0) {
			msgctl(msgid, IPC_RMID, NULL);
			return 0;
		}
		printf("%s", buf.mtext);
	}

	return 0;
}
