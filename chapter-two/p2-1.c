/*
    Determine the ranges of char, short, int and long

    TODO: *To calculate floating type variable ranges min max

          *Can still make the code look better by using MACROS
           Revisit this once you have a good working knowledge on
           MACROS like #define, which can have functions defined in it

    Note: *To correctly use variable types and their corresponding
           format specifier is very important.
           When using constants like 1, they are implicitly INT
           so, we should type cast or use L or LL to convert it into LONG
           and perform the work accordingly.

          *Long number of bits can vary from one machine arch to other
           So, it is usually safe to use long long instead of long which is
           always 64-bits
*/

#include<stdio.h>
#include<limits.h>

#define ZERO             0 //All bits are set to 0
#define ZERO_NEGATION   ~0 //All bits are set to 1 (usually value of -1 for signed and MAX for unsigned)

#define CHAR_BITS       sizeof(char) * 8
#define SHORT_BITS      sizeof(short) * 8
#define INT_BITS        sizeof(int) * 8
#define LONG_BITS       sizeof(long) * 8
#define LONG_LONG_BITS  sizeof(long long) * 8

int main(void)
{
    unsigned char uc = ZERO;
    unsigned short us = ZERO;
    unsigned int ui = ZERO;
    unsigned long ul = ZERO;
    unsigned long long ull = ZERO;

    //Ranges of unsigned data type variables
    printf("Unsigned Data Type Variables MIN & MAX\n");
    printf("CHAR\t\t%hhu %hhu\n", uc, ~uc);
    printf("SHORT\t\t%hu %hu\n", us, ~us);
    printf("INT\t\t%u %u\n", ui, ~ui);
    printf("LONG\t\t%lu %lu\n", ul, ~ul); //long can vary from machine to machine
    printf("LONG LONG\t%llu %llu\n", ull, ~ull); //long long mostly stays as 64 bit

    char c = ZERO_NEGATION;
    short s = ZERO_NEGATION;
    int i = ZERO_NEGATION;
    long l = ZERO_NEGATION;
    long long ll = ZERO_NEGATION;

    //Ranges of signed data type variables
    printf("\nSigned Data Type Variables MIN & MAX\n");
    printf("CHAR\t\t%hhi %hhi\n", (1 << CHAR_BITS - 1) ,c ^ (1 << (CHAR_BITS - 1)));
    printf("SHORT\t\t%hi %hi\n", (1 << (SHORT_BITS - 1)) ,s ^ (1 << (SHORT_BITS - 1)));
    printf("INT\t\t%i %i\n", (1 << (INT_BITS - 1)) ,i ^ (1 << (INT_BITS - 1)));
    printf("LONG\t\t%li %li\n", (1L << (LONG_BITS - 1)) ,l ^ (1L << (LONG_BITS - 1)));
    printf("LONG LONG\t%lli %lli\n", (1LL << (LONG_LONG_BITS - 1)) ,ll ^ (1LL << (LONG_LONG_BITS - 1)));

    return 0;
}
