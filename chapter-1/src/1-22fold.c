#include <stdio.h>
#include <stdlib.h>
#define FOLD 10
#define MAXLINE 100

int mygetline(char s[], int limit);
int foldposition(char in[], int column);
int splitline(char Lout[], char Rout[], char in[], int foldhere);

int main(void)
{
    int i, j, length, foldhere, remlength;
    char line[MAXLINE];
    char Lpart[MAXLINE];
    char Rpart[MAXLINE];

    while ((length = mygetline(line, MAXLINE)) > 0)
    {
        if (length > MAXLINE){
            printf("Too long line\n"); return(1); exit(EXIT_FAILURE);} 
        
        printf("line = %s", line);
        
        foldhere = foldposition(line, FOLD);
        //printf("foldhere = %d ", foldhere);
        remlength = splitline(Lpart, Rpart, line, foldhere);        
        //printf("remlength = %d\n", remlength);
        printf("Lpart = %s", Lpart);
        printf("Rpart = %s", Rpart);
        
    }
    return 0;
}

int splitline(char Lout[], char Rout[], char in[], int foldhere) //return length of Rout
{
    int i;

    if (foldhere == 0)
    {
        i = 0;
        while (in[i] != '\0')
        {
            Lout[i] = in[i];
            ++i;
        }
        Lout[i] = '\0';
        return i;
    }
    else
    {
        i = 0;
        while (i <= foldhere)
        {
            Lout[i] = in[i];
            ++i;
        }
        Lout[i] = '\n';
        ++i;
        Lout[i] = '\0';
    
        i = 0;     
        while (in[i] != '\n' && in[i] != '\0')
        {
            Rout[i] = in[i+foldhere+1];
            ++i;
        }
        Rout[i] = '\0';

        return i-foldhere-1;
    }
}

//foldposition function is more general than necessary: 
//in this context the outter while should only run till 'column'
int foldposition(char in[], int column) 
{                                       
    int i, j;

    i = 0;
    while (in[i] != '\0')
    {
        if (i%column == column-1)
        {
            j = i; 
            if (in[j] == ' ') //last character is blank
            {
                while (in[j] == ' ')
                    --j;
                return (j == 0) ? column-1 : j;
            }    
            else if (in[j] != ' ') //last character is not blank
            {
                while (in[j] != ' ' && j > 0)
                    --j;
                while (in[j] == ' ')
                    --j;
                return (j == 0) ? column-1 : j;
            }
        }
        ++i;
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