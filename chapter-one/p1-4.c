/*
  Program to convert Celcius to Farhenheit
  From 0 to 300 Celcius with a step of 20 each
*/
#include<stdio.h>

float CalculateFarhenheit(float c)
{
    /*
      Formula for conversion Celcius to Farhenheit:f = (c * (9/5)) + 32)
      float values give more precise values
    */
    return (c * (9.0/5.0)) + 32.0;
}

int main(void)
{
    float celcius = 0.0;
    int upper = 300, step = 20;
    printf("Celcius\tFarhenheit\n");
    while(celcius <= upper)
    {
        printf("%3.0f\t\t%6.1f\n", celcius, CalculateFarhenheit(celcius));
        celcius += step;
    }
    return 0;
}
