/*
  Copy input to output, replacing tab with \t and backspace with \b
  and backslash with \\. This makes tabs and backspaces visible in
  an unambiguous way.

  Note : backspace is not recognized as a character as terminal itself
         handles it. So, we can't print \b replacing backspaces
*/
#include<stdio.h>
int main(void)
{
    int c = 0;
    for(;(c = getchar()) != EOF;)
    {
        if(c == '\t')
            printf("\\t");
        else if(c == '\b')
            printf("\\b");
        else if(c == '\\')
            printf("\\");
        else
            printf("%c", c);
    }
    return 0;
}
