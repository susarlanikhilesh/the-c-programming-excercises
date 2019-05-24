/*
    Convert given string from hexadecimal to integer.
    Valid input are 0 .. 9, a .. f, A .. F

    Note: *ld returned 1 exit status - undefined reference to pow function.
           Even though the function header is included math.h, it still produces error.
           The error is from the linker, it is not able to find the implementation
           of pow function where the function definition is in math.h header.
           So, we should gcc programme-name -lm to link the compiler to that function
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_LEN 10
#define HEXADECIMAL 16

char s[MAX_LEN];
int res = 0;

void ReadInput(void)
{
    extern char s[];
    int i = 0;
    for(int c = 0; i < MAX_LEN && (c = getchar()) != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
    return;
}

int ConvertHexAlphaToInt(char c)
{
    switch (c)
    {
        case 'A':
        case 'a':
            return 10;
        case 'B':
        case 'b':
            return 11;
        case 'C':
        case 'c':
            return 12;
        case 'D':
        case 'd':
            return 13;
        case 'E':
        case 'e':
            return 14;
        case 'F':
        case 'f':
            return 15;
    }
    return -1;
}

int ConvertHexToInt(char c)
{
    return isdigit(c) ? c - '0' : ConvertHexAlphaToInt(c);
}

void htoi(void)
{
    extern int res;
    int len = strlen(s);
    for(int i = 0; s[i] != '\0'; i++)
    {
        int temp = ConvertHexToInt(s[i]);
        res += (temp * pow(HEXADECIMAL, --len));
    }
    return;
}

int main(void)
{
    ReadInput();
    printf("%s\n", s);
    htoi();
    printf("%i\n", res);
    return 0;
}
