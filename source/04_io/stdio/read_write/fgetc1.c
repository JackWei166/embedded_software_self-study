#include <stdio.h>


//int main(int argc, char *argv[]){   //xxx 函数程序肯定有个main作为入口的；即使函数再简单都要有 和shell脚本、python（？）不同 

	int ch = fgetc(stdin);   //xxx 全局变量初始化，必须是常数;回头可以声明和赋值拆分看看

	printf("%c\n", ch);    //xxx 任何执行语句，如函数调用必须在函数内
// xxx 实践出真知呀，实践过程中，有疑问觉得有价值的一定不能错过
	//return 0;
//}


/*
	int ch = fgetc(stdin);

	printf("%c\n", ch);
*/
