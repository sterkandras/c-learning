#include <stdio.h>
#define FOLD 10

int main(void)
{
    int i, j;
    int gc;
    int pc;
    int nblank; //number of previous blanks
    int wasNL; //last written chracter was a new line

    i = 0;
    nblank = 0;
    wasNL = 0;
    while ((gc=getchar()) != EOF)
    {
        if (gc==' ')
        {
            ++nblank;
            if (i%FOLD == FOLD-1 && wasNL == 0)
            {
                putchar('\n');
                wasNL = 1;
                nblank = 0;
            }
            else if (gc == ' ')
            {
                --nblank;
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
            wasNL = 0;
        }
        if (gc=='\n')
            i = 0;        
    }
}