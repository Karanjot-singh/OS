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