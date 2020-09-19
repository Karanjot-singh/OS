/*
The code below is commented to eaach code step. 

Explanation for cases : char = 1 byte * 64 = 64 bytes
8 integers = 16 * (4 bytes) = 64 bytes
16 long ints = 8 * (8 bytes) = 64 bytes

We use pointers to store the integers in the array	

*/


#include<stdio.h>

int main(int argc, char* argv[]){
	int n;// Any random garbage value
	long int l;// Any random garbage value
	char x[64]; //Given Character Array

    //Loop to store 64 bit ints
	for (int i = 0; i < 8; ++i){
	    long int *p1 = (long int*)(x); //New pointer of type int points to base of the array
		*(p1+i) = l+i;// Storing the value in the character array
		printf("%ld\n",*(p1+i) );//Printing the value of integers inside  the array
	}
	
	//Loop to store 32 bit ints
	for (int i = 0; i < 16; ++i){
	    int *p2 = (int*)(x); // New pointer of type int points to base of the array
		*(p2+i) = n+i; // Storing the value in the character array
		printf("%d\n",*(p2+i) ); //Printing the value of integers inside  the array
	}
	return 0;
}
