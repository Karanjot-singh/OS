#include <stdio.h>

void main(){

	//code 1
	int i = 90;
float f = 3;
printf("f = %f i = %d\n", f)// f is correct garbage val for i;
printf("f = %f\n", f, i)// ignores i;
printf("i = %d f = %f\n", f, i)// prints i =90 and f= 3.0000... arguments type matter not order;


}