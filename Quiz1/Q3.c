#include<stdio.h>

int main(int argc, char *argv[]){
	int n;
	long int l;// Any random 
	char x[64];


    //64 bit ints
	for (int i = 0; i < 8; ++i){
	    long int *p1 = (long int*)(&x[0]);
		*(p1+i) = l;
	}
	
	//32 bit ints
	for (int i = 0; i < 16; ++i){
	    int *p2 = (int*)(&x[0]);
		*(p2+i) = n;
	}

	//malloc code


	return 0;
}