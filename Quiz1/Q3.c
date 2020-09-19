#include<stdio.h>

int main(){
	int n;// Any random garbage value
	long int l;// Any random garbage value
	char x[64]; //Given Character Array

int arr[] ={1,2,3,4};
int *p=arr;

for (int i = 0; i < 8; ++i){
	printf("%d\n",*(p+i));
 
 }
 //    //Loop to store 64 bit ints
	// for (int i = 0; i < 8; ++i){
	//     long int *p1 = (long int*)(&x[0]); //
	// 	*(p1+i) = l;
	// }
	
	// //32 bit ints
	// for (int i = 0; i < 16; ++i){
	//     int *p2 = (int*)(&x[0]);
	// 	*(p2+i) = n;
	// }



	return 0;
}