#include "data_global.h"
#include "linuxuart.h"

extern struct msg msgbuf;
extern pthread_mutex_t mutex_sms;
extern pthread_cond_t cond_sms;
extern char recive_phone[12];
extern char center_phone[12];

extern char *message;

int gprs_fd;


void call_tel(char *tel);
void send_message(char *tel,char *msg);

void *pthread_sms(void *arg)
{	
	printf("pthread_sms\n");

	while(1){
		pthread_mutex_lock(&mutex_sms);
		pthread_cond_wait(&cond_sms,&mutex_sms);
		if ((gprs_fd = open_port(GPRS_DEV)) < 0){
			perror("open_port");
			return ;
		}
		printf("gprs_fd :%d.\n",gprs_fd);

		if (set_com_config(gprs_fd, 9600, 8, 'N', 1) < 0)
		{
			perror("set_com_config");
			return;
		}
		sleep(1);
		call_tel(recive_phone);
		//send_message(recive_phone,message);
		close(gprs_fd);
		pthread_mutex_unlock(&mutex_sms);	
	}


}



void call_tel(char *tel)
{
	printf("enter call_tel .....\n");
	int n=0,ret=0,num=0;
	char end=26;
	char buff[128]={0};

	memset(buff,0,128);//测试串口是否正常工作，尽可能的多判断返回值
	strcpy(buff,"AT\n");
	write (gprs_fd,buff,strlen(buff));
	read(gprs_fd,buff,128);		
	if(strncmp(buff,"OK",2)){
		printf("serial port connected success \n");	
	}else{
		printf("serial port connected failed  \n");
	}	
	sleep(1);		

	printf("tel ......\n");
	memset(buff,0,128);
	sprintf(buff,"ATD%s;",recive_phone);  //打电话
	strcat(buff,"\n");
	printf("buff :%s.\n",buff);
	write (gprs_fd,buff,strlen(buff));
	read(gprs_fd,buff,128);
	printf("read from gprs 拨打:%s\n",buff);

	sleep(15); //15s之后挂断
	printf("挂断.....");
	memset(buff,0,128);//挂断电话
	strcpy(buff,"ATH;");
	strcat(buff,"\n");
	write (gprs_fd,buff,strlen(buff));
	read(gprs_fd,buff,128);
	printf("read from gprs 挂断:%s\n",buff);

	sleep(15);
	printf("重拨....\n");
	memset(buff,0,128);//测试串口是否正常工作，尽可能的多判断返回值
	strcpy(buff,"ATDL;");
	strcat(buff,"\n");
	write (gprs_fd,buff,strlen(buff));
	read(gprs_fd,buff,128);
	printf("read from gprs 重拨:%s\n",buff);

	sleep(10);
	return ;
}




void send_message(char *tel,char *msg)
{
	printf("enter send_message .....\n");
	int n=0,ret=0,num=0;
	char end=26;
	char buff[128]={0};

	memset(buff,0,128);//测试串口是否正常工作，尽可能的多判断返回值
	strcpy(buff,"AT\n");
	write (gprs_fd,buff,strlen(buff));
	read(gprs_fd,buff,128);		
	if(strncmp(buff,"OK",2)){
		printf("serial port connected success \n");	
	}else{
		printf("serial port connected failed  \n");
	}	
	usleep(10000);		

	memset(buff,0,128);								
	strcpy(buff,"AT+CPIN?\n");//查询是否检测到SIM卡
	write (gprs_fd,buff,strlen(buff));          								
	read(gprs_fd,buff,128);
	printf("set coding type success,SIM卡成功检测到.\n");				
	usleep(10000);


	memset(buff,0,128);									
	strcpy(buff,"AT+CMGF=1\n");         //设置短信发送模式
	write (gprs_fd,buff,strlen(buff));  // CMGF :0(默认)：PDU模式 1：文本模式
	read(gprs_fd,buff,128);
	if(strncmp(buff,"OK",2)){
		printf("set message type success \n");
	}else{
		printf("set message type failed\n");
	}				
	usleep(100000);

	memset(buff,0,128);										
	strcpy(buff,"AT+CSCS?\n");                          //查询短信编码方式 , CSCS编码设置 短信相关常用主要是GSM、UCS2编码格式				
	write (gprs_fd,buff,strlen(buff));						// 模块会根据SIM卡自动设置短消息中心号码，只做查询即可
	read(gprs_fd,buff,128);			
	printf("the coding type is \n");				
	usleep(100000);


	memset(buff,0,128);
	strcpy(buff,"AT+CSMP=17,167,0,240\n");         //参数4：241 短信存在sim卡中 240直接在终端显示			
	write (gprs_fd,buff,strlen(buff));
	read(gprs_fd,buff,128);usleep(10000);
	printf("message save at sim card!\n");
	usleep(100000);

	memset(buff,0,128);
	strcpy(buff,"AT+CMGDA=6\n");        			 //删除之前发送的信息与指令		
	write (gprs_fd,buff,strlen(buff));					
	read(gprs_fd,buff,128);
	if(strncmp(buff,"OK",2)){
		printf("delect message success!\n");				
	}else{
		printf("delect failed!\n");		
	}						

	memset(buff,0,128);
	printf("recive_phone :%s strlen %d sizeof %d.\n",recive_phone,strlen(recive_phone),sizeof(recive_phone)/sizeof(recive_phone[0]));
	sprintf(buff,"AT+CMGS=\"%s\"",recive_phone);  //发送短信
	strcat(buff,"\n");
	write (gprs_fd,buff,strlen(buff));
	read(gprs_fd,buff,128);
	if(strncmp(buff,">",1))
	{
		if(message=='\0')
		{
			printf("please input the message information :");					
			scanf("%s",buff);	
			//strcpy(buff,"hello boy,come on!.\n");
			write(gprs_fd,buff,strlen(buff));					
			read(gprs_fd,buff,128);	
			write(gprs_fd,&end,1);
			read(gprs_fd,buff,128);
		}else{
			strcpy(buff,message);
			write(gprs_fd,buff,strlen(buff));					
			read(gprs_fd,buff,128);	
			write(gprs_fd,&end,1);
			read(gprs_fd,buff,128);	
		}

		n=strlen(buff);
		if(strncmp(&buff[n-1],"O",1)&&strncmp(&buff[n],"K",1)){
			printf("send message success :%s\n",msg);
		}else{
			printf("send message failed\n");
		}
		sleep(1);
	}else{					
		printf("send message failed!\n");
	}	
	sleep(2);
	return ;
}








