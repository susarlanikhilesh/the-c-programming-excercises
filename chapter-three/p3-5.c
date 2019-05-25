/*
    Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s .
    In particular, itob(n,s,16) formats n as a hexadecimal integer in s .

    Didn't handle any negative numbers
*/

#include<stdio.h>

#define MAX_LEN 1000
#define BINARY      2
#define OCTAL       8
#define HEXADECIMAL 16

char binary[MAX_LEN];
char octal[MAX_LEN];
char hexadecimal[MAX_LEN];
char res[MAX_LEN];

//To reverse a string
void Reverse(int end, char *s)
{
    for(int i = 0, j = end - 1; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return;
}

//Individual function to convert decimal to binary
void ConvertToBinary(int n)
{
    int i = 0;
    while(n)
    {
        if(n % 2)   binary[i++] = '1';
        else        binary[i++] = '0';
        n /= 2;
    }
    binary[i] = '\0';
    Reverse(i, binary);
    return;
}

//Individual function to convert decimal to octal
void ConvertToOctal(int n)
{
    int i = 0;
    while(n)
    {
        int rem = n % 8;
        octal[i++] = rem + '0';
        n /= 8;
    }
    octal[i] = '\0';
    Reverse(i, octal);
    return;
}

char ConvertHexIntToAlpha(int c)
{
    switch (c)
    {
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        default: return c + '0';
    }
}

//Individual function to convert decimal to hexadecimal
void ConvertToHexadecimal(int n)
{
    int i = 0;
    while(n)
    {
        int rem = n % 16;
        hexadecimal[i++] = ConvertHexIntToAlpha(rem);
        n /= 16;
    }
    hexadecimal[i] = '\0';
    Reverse(i, hexadecimal);
    return;
}

void Convert(int n)
{
    ConvertToBinary(n);
    ConvertToOctal(n);
    ConvertToHexadecimal(n);
    return;
}

char ConvertAccordingToBase(int n, int base)
{
    if(base == BINARY || base == OCTAL)
        return n + '0';
    return ConvertHexIntToAlpha(n);
}

//Converting a number to given base
void ConvertBase(int n, int base)
{
    int i = 0;
    while(n)
    {
        int rem = n % base;
        res[i++] = ConvertAccordingToBase(rem, base);
        n /= base;
    }
    res[i] = '\0';
    Reverse(i, res);
    return;
}

int main(void)
{
    int n = 0;
    scanf("%i", &n);
    Convert(n);
    printf("%s\n%s\n%s\n", binary, octal, hexadecimal);
    int base = 0;
    scanf("%i", &base);
    ConvertBase(n, base);
    printf("%s", res);
    return 0;
}
