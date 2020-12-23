//replaces blanks in the input with the minimum number of tabs and blanks 
//to space to the next tab stop
#include <stdio.h>
#define TABSTOP 4

int main(void)
{
    int i, j;
    int gc;
    int pc;
    int nblank; //number of previous blanks

    i = 0;
    nblank = 0;
    while ((gc=getchar()) != EOF)
    {
        if (gc==' ')
        {
            ++nblank;
            if(i%TABSTOP == 3)
            {
                putchar('\t');
                nblank = 0;
            }
            ++i;
        }
        else
        {
            while (nblank > 0)
            {
                putchar(' ');
                --nblank;
            }
            putchar(gc);
            ++i;
            nblank = 0;
        }
        if (gc=='\n')
            i = 0;        
    }
}