
//run nasm -f elf64 Q1.asm -o Q1.o && gcc -nostdlib Q1_c.c Q1.o -o checkGreater && ./checkGreater

#include<stdio.h>

extern void checkGreater(); //To link the assembly file with the Addition Function


int main(int argc, char *argv[]){
	checkGreater();
	return 0;
}