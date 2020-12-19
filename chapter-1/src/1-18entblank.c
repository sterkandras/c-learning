#include <stdio.h>

#define MAXLENGTH 1000

int mygetline(char line[], int maxline);
void entblank(char to[], char from[]);

int main(void)
{
    char currentline[MAXLENGTH];
    char newline[MAXLENGTH];
    int length = 1; 
    
    while ((length = mygetline(currentline, MAXLENGTH)) > 0)
    {
        printf("currentline: %s\n", currentline);
        entblank(newline, currentline);
        printf("newline:     %s\n", newline);
    }
}

//remove trailing blanks and tabs from each line of input, and delete entirely blank lines
void entblank(char to[], char from[])
{
    int i;

    i = 0;
    printf("--entblank--\n");
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
    while ((to[i-2] == ' ') || (to[i-1] == '\t'))
    {
        to[i-2] = '\n';
        to[i-1] = '\0';
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