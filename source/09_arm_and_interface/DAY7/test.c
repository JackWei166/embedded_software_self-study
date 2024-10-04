
void func_c(void){
	int a = 0;
	a++;
	
	asm(
		"MOV R6, #6\n"
		"MOV R7, #7\n"
	);
	
	FUNC_ASM();
	
	a--;
}