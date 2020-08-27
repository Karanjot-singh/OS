//plag
#include <stdio.h>

extern int Addition(int x, int y);

int main(int argc, char *argv[]){
    int total;

    total = Addition(4, 2);
    printf("%d\n", total);
    return 0;
}