#include "data_global.h"

#include "buzzer.h"
#include "linuxuart.h"

extern int msgid;
extern key_t key;

extern pthread_mutex_t mutex_client_request,
	   mutex_refresh,
	   mutex_sqlite,
	   mutex_transfer,
	   mutex_analysis,
	   mutex_sms,
	   mutex_buzzer,
	   mutex_led,
	   mutex_camera;

extern pthread_cond_t  cond_client_request,
	   cond_refresh,
	   cond_sqlite,
	   cond_transfer,
	   cond_analysis,
	   cond_sms,
	   cond_buzzer,
	   cond_led,
	   cond_camera;

extern unsigned char cmd_led;
extern unsigned char cmd_buzzer;
extern unsigned char cmd_seg;
extern unsigned char cmd_fan;


extern char recive_phone[12] ;
extern char center_phone[12] ;


struct msg msgbuf;


//第2N个元素表示声调   第2N+1个元素表示该声调的时间
unsigned char MUSIC[500] ={
	//祝你平安
	0x26,0x20,0x20,0x20,0x20,0x20,0x26,0x10,0x20,0x10,0x20,0x80,0x26,0x20,0x30,0x20,
	0x30,0x20,0x39,0x10,0x30,0x10,0x30,0x80,0x26,0x20,0x20,0x20,0x20,0x20,0x1c,0x20,
	0x20,0x80,0x2b,0x20,0x26,0x20,0x20,0x20,0x2b,0x10,0x26,0x10,0x2b,0x80,0x26,0x20,
	0x30,0x20,0x30,0x20,0x39,0x10,0x26,0x10,0x26,0x60,0x40,0x10,0x39,0x10,0x26,0x20,
	0x30,0x20,0x30,0x20,0x39,0x10,0x26,0x10,0x26,0x80,0x26,0x20,0x2b,0x10,0x2b,0x10,
	0x2b,0x20,0x30,0x10,0x39,0x10,0x26,0x10,0x2b,0x10,0x2b,0x20,0x2b,0x40,0x40,0x20,
	0x20,0x10,0x20,0x10,0x2b,0x10,0x26,0x30,0x30,0x80,0x18,0x20,0x18,0x20,0x26,0x20,
	0x20,0x20,0x20,0x40,0x26,0x20,0x2b,0x20,0x30,0x20,0x30,0x20,0x1c,0x20,0x20,0x20,
	0x20,0x80,0x1c,0x20,0x1c,0x20,0x1c,0x20,0x30,0x20,0x30,0x60,0x39,0x10,0x30,0x10,
	0x20,0x20,0x2b,0x10,0x26,0x10,0x2b,0x10,0x26,0x10,0x26,0x10,0x2b,0x10,0x2b,0x80,
	0x18,0x20,0x18,0x20,0x26,0x20,0x20,0x20,0x20,0x60,0x26,0x10,0x2b,0x20,0x30,0x20,
	0x30,0x20,0x1c,0x20,0x20,0x20,0x20,0x80,0x26,0x20,0x30,0x10,0x30,0x10,0x30,0x20,
	0x39,0x20,0x26,0x10,0x2b,0x10,0x2b,0x20,0x2b,0x40,0x40,0x10,0x40,0x10,0x20,0x10,
	0x20,0x10,0x2b,0x10,0x26,0x30,0x30,0x80,0x00,
#if 0
	0x30,0x1c,0x10,0x20,0x40,0x1c,0x10,0x18,0x10,0x20,0x10,0x1c,0x10,0x18,0x40,0x1c,
	0x20,0x20,0x20,0x1c,0x20,0x18,0x20,0x20,0x80,0xff,0x20,0x30,0x1c,0x10,0x18,0x20,
	0x15,0x20,0x1c,0x20,0x20,0x20,0x26,0x40,0x20,0x20,0x2b,0x20,0x26,0x20,0x20,0x20,
	0x30,0x80,0xff,0x20,0x20,0x1c,0x10,0x18,0x10,0x20,0x20,0x26,0x20,0x2b,0x20,0x30,
	0x20,0x2b,0x40,0x20,0x20,0x1c,0x10,0x18,0x10,0x20,0x20,0x26,0x20,0x2b,0x20,0x30,
	0x20,0x2b,0x40,0x20,0x30,0x1c,0x10,0x18,0x20,0x15,0x20,0x1c,0x20,0x20,0x20,0x26,
	0x40,0x20,0x20,0x2b,0x20,0x26,0x20,0x20,0x20,0x30,0x80,0x20,0x30,0x1c,0x10,0x20,
	0x10,0x1c,0x10,0x20,0x20,0x26,0x20,0x2b,0x20,0x30,0x20,0x2b,0x40,0x20,0x15,0x1f,
	0x05,0x20,0x10,0x1c,0x10,0x20,0x20,0x26,0x20,0x2b,0x20,0x30,0x20,0x2b,0x40,0x20,
	0x30,0x1c,0x10,0x18,0x20,0x15,0x20,0x1c,0x20,0x20,0x20,0x26,0x40,0x20,0x20,0x2b,
	0x20,0x26,0x20,0x20,0x20,0x30,0x30,0x20,0x30,0x1c,0x10,0x18,0x40,0x1c,0x20,0x20,
	0x20,0x26,0x40,0x13,0x60,0x18,0x20,0x15,0x40,0x13,0x40,0x18,0x80,0x00,
#endif
};


void *pthread_client_request(void *arg)
{
	if((key = ftok("/tmp",'g')) < 0){
		perror("ftok failed .\n");
		exit(-1);
	}

	msgid = msgget(key,IPC_CREAT|IPC_EXCL|0666);
	if(msgid == -1)	{
		if(errno == EEXIST){
			msgid = msgget(key,0777);
		}else{
			perror("fail to msgget");
			exit(1);
		}
	}
	printf("pthread_client_request\n");

	while(1){
		bzero(&msgbuf,sizeof(msgbuf));
		printf("wait form client request...\n");
		msgrcv (msgid, &msgbuf, sizeof (msgbuf) - sizeof (long), 1L, 0);
		printf ("Get %ldL msg\n", msgbuf.msgtype);
		printf ("text[0] = %#x\n", msgbuf.text[0]);

		switch(msgbuf.msgtype){
			case 1L:
				pthread_mutex_lock(&mutex_led);
				printf("hello led\n");
				cmd_led = msgbuf.text[0];
				pthread_mutex_unlock(&mutex_led);
				pthread_cond_signal(&cond_led);
				break;
			case 2L:
				pthread_mutex_lock(&mutex_buzzer);
				printf("hello beep\n");
				cmd_buzzer = msgbuf.text[0];
				printf("cmd_buzzer :%#x.\n",cmd_buzzer);
			
				int i = 0;
				int buzzer_fd;
				beep_desc_t beeper;
				buzzer_fd = open(BEEPER_DEV,O_RDWR | O_NONBLOCK);
				if ( buzzer_fd == -1 ) {
					perror("open beeper failed.\n");
					//return -1;
				}
				printf("buzzer_fd ;%d.\n",buzzer_fd);	
				if(cmd_buzzer == 0x51){
					ioctl(buzzer_fd,BEEP_ON);
#if 1
					for(i = 0;i < sizeof(MUSIC)/sizeof(MUSIC[0]); i += 2)
					{
						beeper.tcnt = MUSIC[i];
						beeper.tcmp = MUSIC[i]/2;
						ioctl(buzzer_fd,BEEP_FREQ,&beeper);
						usleep(MUSIC[i+1] * 20000);
					} //耗时操作，尽可能在线程的处理函数中避免耗时操作
					printf("music play over....\n");
					close(buzzer_fd);
#endif 
				}else if(cmd_buzzer == 0x50){
					ioctl(buzzer_fd,BEEP_OFF);
				}else {
					printf("cmd_buzzer error.\n");
				}
				
				pthread_mutex_unlock(&mutex_buzzer);
				break;
			case 3L:
				pthread_mutex_lock(&mutex_led);
				printf("hello seg\n");
				cmd_seg = msgbuf.text[0];
				pthread_mutex_unlock(&mutex_led);
				pthread_cond_signal(&cond_led);
				break;
			case 4L:
				pthread_mutex_lock(&mutex_sqlite);
				printf("hello fan\n");
				cmd_fan = msgbuf.text[0];
				
				int fan_fd = open_port("/dev/ttyUSB0"); //打开设备
				if(fan_fd < 0){
					printf("open failed\n");
				}
				set_com_config(fan_fd, 115200, 8, 'N', 1); //设置串口参数
				
				char cmdbuf[4] = {0};
				if(cmd_fan == 0x21){
					strcpy(cmdbuf,"1\n"); //注意点
					write(fan_fd,cmdbuf,sizeof(cmdbuf)/sizeof(cmdbuf[0]));
					sleep(2);
				}
				if(cmd_fan == 0x20){
					strcpy(cmdbuf,"0\n");
					write(fan_fd,cmdbuf,sizeof(cmdbuf)/sizeof(cmdbuf[0]));
					sleep(2);
				}
				char buf[32] = {0};
				//get data from zigbee
				read(fan_fd,&buf,sizeof(buf));
				printf("sizeof(buf) = %d.\n",sizeof(buf));
				printf(">>>>>>%s\n",buf);
				sleep(1);
				pthread_mutex_unlock(&mutex_sqlite);
				break;
			case 5L:
				printf("set env data\n");
				printf("temMAX: %d\n",*((int *)&msgbuf.text[1]));
				printf("temMIN: %d\n",*((int *)&msgbuf.text[5]));
				printf("humMAX: %d\n",*((int *)&msgbuf.text[9]));
				printf("humMAX: %d\n",*((int *)&msgbuf.text[13]));
				printf("illMAX: %d\n",*((int *)&msgbuf.text[17]));
				printf("illMAX: %d\n",*((int *)&msgbuf.text[21]));

				break;
			case 6L:
			case 7L:
			case 8L:
			case 9L:
				printf("你可以将这些作为扩展来学习，加油.\n");
				break;
			case 10L:
				{
					pthread_mutex_lock (&mutex_sms);
					int i = 0 , j = 0 ;
					for(i = 0 ; i < 11; i++){
						recive_phone[i] = msgbuf.text[i]; 	
					}
					recive_phone[i] = '\0';
					printf("recive:%s\n",recive_phone);
					for(j = 0 ;msgbuf.text[i] != '\0' && j < 12; i++, j++)
					{
						center_phone[j] =  msgbuf.text[i];
					}
					center_phone[j] = '\0';
					printf("center:%s\n",center_phone);
					cmd_sms = msgbuf.text[0];
					pthread_cond_signal(&cond_sms);
					pthread_mutex_unlock(&mutex_sms);
				}
				break;
			default:
				break;

		}
	}

}


#if 0

long msgtype;//具体的消息类型
消息类型的分配：
1L: 		LED控制
2L:			蜂鸣器控制
3L:			四路LED灯模拟的数码管
4L:			风扇
5L:			温湿度最值设置
6L-7L-8L-9L,用于个人的扩展
10L: 		3G通信模块-GPRS 
switch(msgbuf.msgtype){
	case 1L: ...  break;
			 ....
				 default ....  break;
}
#endif 





