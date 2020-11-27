#include <stdio.h>
//#include <limits.h>

int main(){
    int c;

    //printf("%d\n", INT_MAX);

    printf("start: %d\n", (getchar() != EOF));
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    printf("end: %d\n", (getchar() != EOF));
}