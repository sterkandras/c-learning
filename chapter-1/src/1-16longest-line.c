#include <stdio.h>

#define MAXLENGTH 100

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    char longestline[MAXLENGTH];
    char currentline[MAXLENGTH];
    int length;
    int max;

    max = 0;
    while ((length = mygetline(currentline, MAXLENGTH)) > 0)
        if (length > max) {
            max = length;
            copy(longestline, currentline);
        }
    if (max > 0)
        printf("%s", longestline);
    return 0; 
}

int mygetline(char s[], int limit)
{
    int i, c;

    for (i=0; i<limit-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c=='\n') {
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