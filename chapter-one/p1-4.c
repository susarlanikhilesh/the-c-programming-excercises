/*
  Program to convert Farhenheit to Celcius
*/

#include<stdio.h>

float CalculateFarheit(float f)
{
    /*
      Formula for conversion is : (5/9) * (f -32)
      Used float for more precise values
    */
    return (5.0/9.0) * (f - 32.0);
}

int main(void)
{
    float farh = 0.0, celcius = 0.0;
    int upper = 300, step = 20;
    printf("Farhenheit to Celcius\n");
    while(farh <= upper)
    {
        printf("%3.0f%6.1f\n", farh, CalculateFarheit(farh));
        farh += step;
    }
    return 0;
}
