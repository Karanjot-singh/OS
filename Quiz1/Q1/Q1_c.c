// nasm -f elf64 Q1.asm -o Q1.o && gcc --entry=_start -nostdlib Q1_c.c Q1.o -o checkGreater && ./checkGreater
// nasm -f elf64 Q1.asm -o Q1.o && gcc --entry=main -nostdlib Q1_c.c Q1.o -o checkGreater && ./checkGreater

#include<stdio.h>

extern void checkGreater(int x , int y ); //To link the assembly file with the Addition Function


void main(int argc, char *argv[]){
	int x=13;
	int y = 7;
	checkGreater(x,y);
}