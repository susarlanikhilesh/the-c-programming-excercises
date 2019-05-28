/*
    Define a macro swap(t,x,y) that interchanges two arguments of type t
*/

#include<stdio.h>

#define swap(t, x, y) \
            t xy = x;  \
            x = y;     \
            y = xy;    \

int main(void)
{
    float a = 1, b = 2;
    swap(float, a, b);
    printf("%f %f\n", a ,b);
    return 0;
}
