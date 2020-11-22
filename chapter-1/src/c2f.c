#include <stdio.h>

int main(){

    float fahr, celsius;
    int lower, upper, step;
    int i = 0;

    lower = 0;
    upper = 300;
    step = 20;


    printf("Celsius\t\tFahrenheit\n");

    fahr = upper;
    
    while (lower <= fahr){      
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.2f\t\t%3.2f\t\t%3d\n", celsius, fahr, i);
        fahr = fahr - step;
    }
}