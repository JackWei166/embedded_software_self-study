#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define N 64
#define TypeA 1
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
		if (msgrcv(msgid, &buf, LEN, TypeB, 0) < 0) {   
			perror("msgrcv");
			msgctl(msgid, IPC_RMID, NULL);   
			return 1;
		}
		if (strcmp(buf.mtext, "quit\n") == 0) {
			msgctl(msgid, IPC_RMID, NULL);
			return 0;
		}
		printf("%s", buf.mtext);
		
		buf.mtype = TypeA;
		fgets(buf.mtext, N, stdin);
		msgsnd(msgid, &buf, LEN, 0);   
		if (strcmp(buf.mtext, "quit\n") == 0) break;   
	}

	return 0;
}
