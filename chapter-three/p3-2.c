/*
    Function escape(s,t) that converts chars like newline and tabs into
    visible sequence like \n, \t which copying from one string to another
*/

#include<stdio.h>

#define MAX_LEN 100

char s[MAX_LEN];
char t[MAX_LEN];

void ReadInput(void)
{
     scanf("%[^\r]s",s);
    return;
}

void Escape(void)
{
    int i = 0, j = 0;
    for(; s[i] != '\0'; i++, j++)
    {
        if(s[i] == '\n')
        {
            t[j++] = '\\';
            t[j] = 'n';
        }
        else if(s[i] == '\t')
        {
            t[j++] = '\\';
            t[j] = 't';
        }
        else
            t[j] = s[i];
    }

    t[j] = '\0';
    return;
}

int main(void)
{
    ReadInput();
    Escape();
    printf("%s\n", t);
    return 0;
}
