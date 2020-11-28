#include <stdio.h>

#define IN  0
#define OUT 1

int main()
{
    int c, state;

    state = IN;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t' || c == ' ' || c == '\n')
        {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else
        { 
            putchar(c);
            state = IN;
        }    
    }
}