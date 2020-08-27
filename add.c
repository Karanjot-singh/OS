
//run nasm -f elf64 Addition.asm -o Addition.o && gcc add.c Addition.o -o sum && ./sum

#include<stdio.h>

extern int Addition(int a , int b);

int main(int argc, char *argv[]){
	int num1, num2;
	printf("Enter num1 : ");
	scanf("%d",&num1);
	printf("Enter num2 : ");
	scanf("%d",&num2);
	int sum =Addition(num1,num2);	
	printf("\nThe Sum is: %d \n" , sum);

	return 0;
}