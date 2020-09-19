
//run nasm -f elf32 P4_1.asm -o P4_1.o && gcc -m32 P4.c P4_1.o -o sum1 && ./sum1
//run nasm -f elf64 P4_2.asm -o P4_2.o && gcc P4.c P4_2.o -o sum2 && ./sum2

#include<stdio.h>

extern int long_add(int a, int b, int c, int d); //To link the assembly file with the Addition Function
// extern int extended_add(int a, int b, int c, int d);

int main(int argc, char *argv[]){
	int a =1;
	int b = -3;
	int c = 5;
	int d =0;
	int sum = long_add(a,b,c,d);
	// int sum = extended_add(a,b,c,d);

	printf("Sum: %d\n", sum);
	return 0;
}