//replaces tabs in the input with the proper number of blanks to space to the next tab stop
#include <stdio.h>
#define TABSTOP 4

int main(void)
{
    int i, j;
    int gc;
    int pc;

    i = 0;
    while ((gc=getchar()) != EOF)
    {
        if (gc=='\t')
        {
            j=TABSTOP-i%TABSTOP;
            while (j>0)
            {
                putchar(' ');
                --j;
                ++i;
            }
        }
        else
        {
            putchar(gc);
            ++i;
        }
        if (gc=='\n')
            i = 0;        
    }
}