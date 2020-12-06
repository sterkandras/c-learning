#include <stdio.h>

#define LONGESTWORD 10

int main()
{
    int i, c, length, wlength[LONGESTWORD];

    for (i = 0; i < LONGESTWORD; ++i)
        wlength[i] = 0;

    length = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t' || c == ' ' || c == '\n')
        {
            if (length != 0)
                ++wlength[length-1];
            length = 0;
        }
        else
        { 
            ++length;           
        }              
    }

    for(i = 0; i < LONGESTWORD; i++)  
        printf("%d ", wlength[i]);
    printf("\n");    
    for(i = 0; i < LONGESTWORD; i++)
        printf("%d ", i); 
    printf("\n"); 

}