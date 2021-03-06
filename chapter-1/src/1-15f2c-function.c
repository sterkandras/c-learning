#include <stdio.h>

/*print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300*/

int f2c(int);

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;    /*lower limit of temperature table*/
    upper = 300;  /*upper limit of temperature table*/
    step = 20;    /*step size*/

    fahr = lower;

    printf("Fahrenheit\tCelsius\n");

    while (fahr <= upper) {
        celsius = f2c(fahr);
        printf ("%d\t\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 1;
}

int f2c(int f)
{
    return 5 * (f-32) / 9; 
}