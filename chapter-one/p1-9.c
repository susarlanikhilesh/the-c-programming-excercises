/*
  Copy input lines to ouput, replacing each string of one or
  more blanks by single blank
*/
#include<stdio.h>

#define YES 1
#define NO  0

int main(void)
{
    int c = 0, isSpacePrinted = NO;
    for(;(c = getchar()) != EOF;)
    {
        if(c == ' ' && !isSpacePrinted)
        {
            printf(" ");
            isSpacePrinted = YES;
        }
        else if(c != ' ')
        {
            isSpacePrinted = NO;
            c == '\n' ? printf("\n") : printf("%c", c);
        }
    }
    return 0;
}
