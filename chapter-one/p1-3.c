/*
  Program to convert Farhenheit to Celcius
  From 0 to 300 Farhenheit with a step of 20 each
*/
#include<stdio.h>

float CalculateCelcius(float f)
{
    /*
      Formula for conversion Farhenheit to Celcius :c = (5/9) * (f - 32)
      float values give more precise values
      Using integers makes the formula look different in programming :
      (5 * (f - 32)) / 9 (Since 5/9 turncates to zero as integer division is being perfomred)
    */
    return (5.0/9.0) * (f - 32.0);
}

int main(void)
{
    float farh = 0.0, celcius = 0.0;
    int upper = 300, step = 20;
    printf("Farhenheit\tCelcius\n");
    while(farh <= upper)
    {
        printf("%3.0f\t\t%6.1f\n", farh, CalculateCelcius(farh));
        farh += step;
    }
    return 0;
}
