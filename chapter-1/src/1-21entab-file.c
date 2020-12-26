//replaces blanks in the input with the minimum number of tabs and blanks 
//to space to the next tab stop
#include <stdio.h>
#define TABSTOP 4

int main(void)
{
    FILE  *fpIn, *fpOut;
    int i;
    int gc;
    int pc;
    int nblank; //number of previous blanks

    fpIn = fopen("tmp\\input.txt", "r");
    fpOut = fopen("tmp\\output.txt", "w+");
    if((fpIn || fpOut)==0){
        printf("Error opening file\n"); return 1;}
    
    i = 0;
    nblank = 0;
    while ((gc=fgetc(fpIn)) != EOF)
    {
        if (gc==' ')
        {
            ++nblank;
            if(i%TABSTOP == TABSTOP-1)
            {
                if(fputc('\t', fpOut)==EOF){
                    printf("Error writing to file\n"); return 1;}
                nblank = 0;
            }
            ++i;
        }
        else
        {
            while (nblank > 0)
            {
                if(fputc(' ', fpOut)==EOF){
                    printf("Error writing to file\n"); return 1;}
                --nblank;
            }
            if(fputc(gc, fpOut)==EOF){
                printf("Error writing to file\n"); return 1;}
            ++i;
            nblank = 0;
        }
        if (gc=='\n')
            i = 0;        
    }
}