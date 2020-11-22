#include <stdio.h>
//#include <limits.h>

int main(){
    int c;

    //printf("EOF = %d\n", EOF);
    //c = getchar();
    //printf("%d\n", INT_MAX);

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}