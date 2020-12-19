#include <stdio.h>

#define MAXLENGTH 1000

int mygetline(char line[], int maxline);
void reverse(char reverse[], char string[]);

int main(void)
{
    char currentline[MAXLENGTH];
    char newline[MAXLENGTH];
    int length = 1; 
    
    while ((length = mygetline(currentline, MAXLENGTH)) > 0)
    {
        printf("currentline: %s\n", currentline);
        reverse(newline, currentline);
        printf("newline:     %s\n", newline);
    }
}

//reverse the character string s
void reverse(char rs[], char s[])
{
    int i, l;

    i = 0;
    printf("--reverse--\n");
    while ((rs[i] = s[i]) != '\0')
        ++i;
    l = i;
    while (i > 1)
    {
        rs[i-2] = s[l-i];
        --i;
    }
}

int mygetline(char s[], int limit)
{
    int i, c;

    for (i=0; i<limit-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }   
    s[i] = '\0';
    return i;
}