#include<stdio.h>

int main(int argc, char *argv[]){

	int noOfInts = 16;
	int noOfLongInts = 8;

	int *p1 = (long int*)malloc(n * sizeof(long int)); 
	int *p2;
	 if (ptr == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
        // Memory has been successfully allocated 
        printf("Memory successfully allocated using malloc.\n"); 
  
        // Get the elements of the array 
        for (i = 0; i < n; ++i) { 
            ptr[i] = i + 1; 
        } 
  
        // Print the elements of the array 
        printf("The elements of the array are: "); 
        for (i = 0; i < n; ++i) { 
            printf("%d, ", ptr[i]); 
        } 
    } 

	return 0;
}