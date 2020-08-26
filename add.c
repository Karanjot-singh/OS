#include<stdio.h>

extern void Addition(int a , int b);
void main(){
	int num1, num2;
	printf("Enter num1 : ");
	scanf("%d",&num1);
	printf("Enter num2 : ");
	scanf("%d",&num2);
	printf("\n The Sum is: ");
	Addition(num1,num2);
}