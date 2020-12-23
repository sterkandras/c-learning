//replaces tabs in the input with the proper number of blanks to space to the next tab stop
#include <stdio.h>
#define TABSTOP 4

int main(void)
{
    FILE  *fpIn, *fpOut;
    int i, j;
    int gc;
    int pc;

    fpIn = fopen("tmp\\input.txt", "r");
    fpOut = fopen("tmp\\output.txt", "w+");
    if((fpIn || fpOut)==0){
        printf("Error opening file\n"); return 1;}
    i = 0;
    while ((gc=fgetc(fpIn)) != EOF)
    {
        if (gc=='\t')
        {
            j=TABSTOP-i%TABSTOP;
            while (j>0)
            {
                if(fputc(' ', fpOut)==EOF){
                    printf("Error writing to file\n"); return 1;}
                --j;
                ++i;
            }
        }
        else
        {
            if(fputc(gc, fpOut)==EOF){
                printf("Error writing to file\n"); return 1;}
            ++i;
        }
        if (gc=='\n')
            i = 0;        
    }
    fclose(fpIn);
    fclose(fpOut);
    return 0;
}