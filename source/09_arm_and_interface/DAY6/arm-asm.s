.text
.global _start

_start:
	@ R2 = 1  @xxx =赋值不存在的，得用mov
	@ R1 = R2  @xxx 如上，同样不对
	@ MOV R2, #1
	@ MOV R1, R2
	@ MOV R1, #2
	
	@ MVN R0, #0xFF
	
	@ MOV R0, #0x12345678   @xxx 编译通不过，无效常数
	
	@ MOV R0, #0xFFFFFFFF   @xxx 编译器做了转化，转成mvn了
	
	@ MOV R2, #2
	@ MOV R3, #3
	@ ADD R1, R2, R3
	@ ADD R1, R2, #5
	
	@ MOV R2, #2
	@ MOV R3, #3
	@ SUB R1, R2, R3
	@ SUB R1, R2, #5
	
	@ RSB R1, R2, R3
	@ RSB R1, R2, #5
	
	@ MUL R1, R2, R3
	
	@ AND R1, R2, R3
	@ AND R1, R2, #5
	
	@ ORR R1, R2, R3
	@ ORR R1, R2, #5
	
	@ EOR R1, R2, R3
	@ EOR R1, R2, #5
	
	@ LSL R1, R2, R3
	@ LSL R1, R2, #1
	
	@ LSR R1, R2, R3
	@ LSR R1, R2, #1
	
	@ MOV R2, #0xFF   @xxx 写立即数，要想十进制还是十六进制 十六别忘0x！！！
	@ BIC R1, R2, #0x0F   @xxx 觉得一般指令，都有三个操作值，一个接受值，两个操作值
	
	@ MOV R2, #3
	@ MOV R1, R2, LSL #1   @xxx 觉得按照我笔记分析这种应该是对的
	
	@ 第一个数
	@ 0x 00000001 FFFFFFFF
	@ 第二个数
	@ 0x 00000002 00000003
	@ MOV R1, #0xFFFFFFFF
	@ MOV R2, #0x00000001
	@ MOV R3, #0x00000003
	@ MOV R4, #0x00000002
	@ ADDS R5, R1, R3
	@ ADC R6, R2, R4
	
	@ 第一个数
	@ 0x 00000002 00000001
	@ 第二个数
	@ 0x 00000001 00000005
	@ MOV R1, #0x00000001
	@ MOV R2, #0x00000002
	@ MOV R3, #0x00000005
	@ MOV R4, #0x00000001
	@ SUBS R5, R1, R3
	@ SBC R6, R2, R4





@ MAIN:   @xxx 注意别用中文的冒号！！！否则报错
	@ MOV R1, #1
	@ MOV R2, #2
	@ MOV R3, #3
	@ MOV PC, #0x18   @xxx pc可以像平常的寄存器一样改，cpsr就不行了
	@ MOV R4, #4
	@ MOV R5, #5

@ FUNC:
	@ MOV R6, #6
	@ MOV R7, #7
	@ MOV R8, #8
	
@ MAIN:
	@ MOV R1, #1
	@ MOV R2, #2
	@ MOV R3, #3
	@ B FUNC
	@ MOV R4, #4
	@ MOV R5, #5

@ FUNC:
	@ MOV R6, #6
	@ MOV R7, #7
	@ MOV R8, #8

@ MAIN:
	@ MOV R1, #1
	@ MOV R2, #2
	@ MOV R3, #3
	@ BL FUNC
	@ MOV R4, #4
	@ MOV R5, #5

@ FUNC:
	@ MOV R6, #6
	@ MOV R7, #7
	@ MOV R8, #8
	@ MOV PC, LR

@ MAIN:
	@ MOV R1, #1
	@ MOV R2, #2
	@ MOV R3, #3
	@ CMP R2, R3
	@ BLEQ FUNC
	@ BLNE FUNC
	@ MOV R4, #4
	@ MOV R5, #5
/*
FUNC:
	MOV R6, #6
	MOV R7, #7
	MOV R8, #8
	MOV PC, LR
*/    @xxx 看看能多行注释不，还是能，觉得那个百度小米大佬还是可能有知识盲点的

		@ 练习：用汇编语言实现以下逻辑
			@ int R1 = 9;
			@ int R2 = 15;
		@ START:
			@ if(R1 == R2)
			@ {
			@ 	STOP();
			@ }
			@ else if(R1 > R2)
			@ {			
			@ 	R1 = R1 - R2;
			@ 	goto START;
			@ }
			@ else
			@ {
			@ 	R2 = R2 - R1;
			@	goto START;
			@ }
/*
MOV R1, #9
MOV R2, #15

START:
	CMP R1, R2
	BEQ STOP
	SUBGT R1, R1, R2
	SUBLT R2, R2, R1
	B START
*/






/*
MOV R1 #0xFF000000   @xxx 觉得就是演示下
MOV R2 #0x40000000
STR R1, [R2]

LDR R1, [R2]

STRB R1, [R2]
STRH R1, [R2]
*/

/*
MOV R1, #1
ADD R1, R2, #1

ADD R1, R2, R3

MOV R1, R2, LSL #1   @xxx R2后面加逗号

STR R1, [R2]

STR R1, [R2, R3]   @xxx 方括号内也需要逗号

STR R1, [R2, #8]   @xxx 前索引和基址加变址寻址一样的；后索引，自动索引，都在此基础上改

STR R1, [R2], #8

STR R1, [R2, #8]!
*/

/*
STM R11, {R1-R4}
LDM R11, {R6-R9}

STM R11, {R1, R2, R4}
STM R11, {R4, R1, R2}
STM R11!, {R1-R4}   @xxx 有！就自增四个字节，应该是按照默认的FD来吧？ STM DB LDM IA

STMIA R11!, {R1-R4}
STMIB R11!, {R1-R4}
STMDA R11!, {R1-R4}
STMDB R11!, {R1-R4}

STMFD R11!, {R1-R4}
*/

@ 1.叶子函数的调用过程举例 @xxx 觉得函数调用和中断、异常处理基本一样，都是停止、跳过出、处理、跳回来；具体分别是保存pc值、改pc值、改pc值、保护恢复现场（上面用到的寄存器（中断异常更多点处理）
@xxx 有调用再加上LR；对main函数无作用）
/*
MOV SP, #0x40000020   @xxx 要使用栈，必须初始
                      @xxx 否则默认值0，不合法用不了（一开始没初始化，下面代码储存不了R1、R2的值）
MAIN:
	MOV R1, #1
	MOV R2, #2
	BL FUNC
	ADD R3, R1, R2
	B STOP
	
FUNC:
	STMFD SP!, {R1, R2}   @xxx 每个操作数后面记得加逗号（sp一开始没加）
	MOV R1, #10
	MOV R2, #20
	SUB R3, R2, R1
	LDMFD SP!, {R1, R2}
	MOV PC, LR
*/

@ 2.非叶子函数的调用过程举例
/*
MOV SP, #0x40000020

MAIN:
	MOV R1, #1
	MOV R2, #2
	BL FUNC1
	ADD R3, R1, R2
	B STOP

FUNC1:
	STMFD SP!, {R1, R2, LR}
	MOV R1, #10
	MOV R2, #20
	BL FUNC2
	SUB R3, R2, R1
	LDMFD SP!, {R1, R2, LR}
	MOV PC, LR

FUNC2:
	STMFD SP!, {R1, R2}
	MOV R1, #100
	MOV R2, #200
	SUB R3, R2, R1
	LDMFD SP!, {R1, R2}
	MOV PC, LR
*/





MRS R0, CPSR

MSR CPSR, #0x10

STOP:
	b STOP

.end