#include <stdio.h>

int main()
{
    int c, nl, bl, tab;
    
    nl = bl = tab = 0;

    while((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nl;
        if (c == ' ')
            ++bl;
        if (c == '\t')
            ++tab;
    }
    printf("%d %d %d\n",nl,bl,tab);        

}