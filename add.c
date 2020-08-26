#include<stdio.h>

extern int Addition(int a , int b);
void main(){
	int num1, num2;
	printf("Enter num1 : ");
	scanf("%d",&num1);
	printf("\nEnter num2 : ");
	scanf("%d",&num2);
	int sum =Addition(num1,num2);
	printf("\n %d", sum);


}