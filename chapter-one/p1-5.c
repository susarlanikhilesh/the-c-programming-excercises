/*
  Program to convert Farhenheit to Celcius in reverse order
  From 300 to 0 Farhenheit with a step of 20 each
*/
#include<stdio.h>

#define UPPERLIMIT  300.0
#define LOWERLIMIT  0.0
#define STEP        20.0

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
    printf("Farhenheit\tCelcius\n");
    for(float farh = UPPERLIMIT; farh >= LOWERLIMIT; farh -= STEP)
      printf("%3.0f\t\t%6.1f\n", farh, CalculateCelcius(farh));
    return 0;
}
