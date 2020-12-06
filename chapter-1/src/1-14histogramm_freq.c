#include <stdio.h>

int main()
{
    int i, c;
    int nchar[256]; 

    for (i = 0; i < 256; ++i)
        nchar[i] = 0;

    while ((c = getchar()) != EOF)
    {
        ++nchar[c];
    }

    for (i = 0; i < 256; i++)
        printf("%c = %d\n", i, nchar[i]);
}