/*
  Print input line one word per line and count number of words
*/
#include<stdio.h>
int main(void)
{
    int c = 0;
    int wc = 0;
    int flag = 0;
    for(;(c = getchar()) != EOF;)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            c == '\n' ? flag = 0 : printf("\n");
        }
        else if(flag == 0)
        {
            printf("%c", c);
            flag = 1;
            ++wc;
        }
        else
          printf("%c", c);
    }
    printf("Number of words : %d\n", wc);
    return 0;
}
