.text
.global _start

_start:
	@ R2 = 1  @xxx =��ֵ�����ڵģ�����mov
	@ R1 = R2  @xxx ���ϣ�ͬ������
	@ MOV R2, #1
	@ MOV R1, R2
	@ MOV R1, #2
	
	@ MVN R0, #0xFF
	
	@ MOV R0, #0x12345678   @xxx ����ͨ��������Ч����
	
	@ MOV R0, #0xFFFFFFFF   @xxx ����������ת����ת��mvn��
	
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
	
	@ MOV R2, #0xFF   @xxx д��������Ҫ��ʮ���ƻ���ʮ������ ʮ������0x������
	@ BIC R1, R2, #0x0F   @xxx ����һ��ָ�������������ֵ��һ������ֵ����������ֵ
	
	@ MOV R2, #3
	@ MOV R1, R2, LSL #1   @xxx ���ð����ұʼǷ�������Ӧ���ǶԵ�
	
	@ ��һ����
	@ 0x 00000001 FFFFFFFF
	@ �ڶ�����
	@ 0x 00000002 00000003
	@ MOV R1, #0xFFFFFFFF
	@ MOV R2, #0x00000001
	@ MOV R3, #0x00000003
	@ MOV R4, #0x00000002
	@ ADDS R5, R1, R3
	@ ADC R6, R2, R4
	
	@ ��һ����
	@ 0x 00000002 00000001
	@ �ڶ�����
	@ 0x 00000001 00000005
	@ MOV R1, #0x00000001
	@ MOV R2, #0x00000002
	@ MOV R3, #0x00000005
	@ MOV R4, #0x00000001
	@ SUBS R5, R1, R3
	@ SBC R6, R2, R4





@ MAIN:   @xxx ע��������ĵ�ð�ţ��������򱨴�
	@ MOV R1, #1
	@ MOV R2, #2
	@ MOV R3, #3
	@ MOV PC, #0x18   @xxx pc������ƽ���ļĴ���һ���ģ�cpsr�Ͳ�����
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
*/    @xxx �����ܶ���ע�Ͳ��������ܣ������Ǹ��ٶ�С�״��л��ǿ�����֪ʶä���

		@ ��ϰ���û������ʵ�������߼�
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
MOV R1 #0xFF000000   @xxx ���þ�����ʾ��
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

MOV R1, R2, LSL #1   @xxx R2����Ӷ���

STR R1, [R2]

STR R1, [R2, R3]   @xxx ��������Ҳ��Ҫ����

STR R1, [R2, #8]   @xxx ǰ�����ͻ�ַ�ӱ�ַѰַһ���ģ����������Զ����������ڴ˻����ϸ�

STR R1, [R2], #8

STR R1, [R2, #8]!
*/

/*
STM R11, {R1-R4}
LDM R11, {R6-R9}

STM R11, {R1, R2, R4}
STM R11, {R4, R1, R2}
STM R11!, {R1-R4}   @xxx �У��������ĸ��ֽڣ�Ӧ���ǰ���Ĭ�ϵ�FD���ɣ� STM DB LDM IA

STMIA R11!, {R1-R4}
STMIB R11!, {R1-R4}
STMDA R11!, {R1-R4}
STMDB R11!, {R1-R4}

STMFD R11!, {R1-R4}
*/

@ 1.Ҷ�Ӻ����ĵ��ù��̾��� @xxx ���ú������ú��жϡ��쳣�������һ��������ֹͣ��������������������������ֱ��Ǳ���pcֵ����pcֵ����pcֵ�������ָ��ֳ��������õ��ļĴ������ж��쳣����㴦��
@xxx �е����ټ���LR����main���������ã�
/*
MOV SP, #0x40000020   @xxx Ҫʹ��ջ�������ʼ
                      @xxx ����Ĭ��ֵ0�����Ϸ��ò��ˣ�һ��ʼû��ʼ����������봢�治��R1��R2��ֵ��
MAIN:
	MOV R1, #1
	MOV R2, #2
	BL FUNC
	ADD R3, R1, R2
	B STOP
	
FUNC:
	STMFD SP!, {R1, R2}   @xxx ÿ������������ǵüӶ��ţ�spһ��ʼû�ӣ�
	MOV R1, #10
	MOV R2, #20
	SUB R3, R2, R1
	LDMFD SP!, {R1, R2}
	MOV PC, LR
*/

@ 2.��Ҷ�Ӻ����ĵ��ù��̾���
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