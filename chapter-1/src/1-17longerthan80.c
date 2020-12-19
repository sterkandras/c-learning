#include <stdio.h>
#define MAXLENGTH 1000
#define PRINTABOVE 80

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    char longestline[MAXLENGTH];
    char currentline[MAXLENGTH];
    int length;
    int max;
    int reallen;
    int i;

    reallen = 0;
    max = 0;
    i = 0;
    while ((length = mygetline(currentline, MAXLENGTH)) > 0)
    {   
        reallen = reallen + length;
        ++i; 
        if (currentline[length-1] == '\n') {
            i = 0;
            printf("This is the correct length = %d\n", reallen-1);
            if (max > 0 && reallen > PRINTABOVE)
                printf("This line is longer than %d: %s\n", PRINTABOVE, currentline);
            reallen = 0;
        }
        if (length > max) {
            max = length;
            copy(longestline, currentline);
        }
    }    
    if (max > 0 && reallen > PRINTABOVE)
        printf("longest line: %s\n", currentline);
    return 0; 
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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}