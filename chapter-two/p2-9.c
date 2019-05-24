/*
    In two's complement number system, n &= (n - 1) deletes the rightmost
    1-bit in x
*/
#include<stdio.h>

void Print(int n)
{
    printf("%i\t", n);
    for(int i = 0; n != 0; n >>= 1 ,i++)
        printf("%u", n & 1);
    return;
}

int CountNSetBits(int n)
{
    int count = 0;
    while(n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main(void)
{
    for(int i = 0; i < 30; i++)
    {
        Print(i);
        printf("\t\t%i\n", CountNSetBits(i));
    }
    return 0;
}
