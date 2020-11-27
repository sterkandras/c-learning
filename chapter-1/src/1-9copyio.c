#include <stdio.h>

int main(){

    int c;
    int nbl = 0;


    while((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nbl;
        else
            nbl = 0;
            
        if (nbl > 1)
           ;
        else
            putchar(c); 
    }
}