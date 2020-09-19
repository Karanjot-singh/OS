//This program is an example of file handling in C to store the string as a text file in the disk.

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	char* name ="Karanjot Singh";
	FILE *fp;
	fp = fopen("name.txt", "w");
	if( fp ==NULL )
		exit(1);

	fprintf(fp, "%s", name);
	fclose(fp);
	return 0;
}
