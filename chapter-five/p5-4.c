/*
    Write the function strend(s,t) ,
    which returns 1 if the string t occurs at the end of the string s , and zero otherwise.

*/

#include <stdio.h>

#define MAXLEN 1000

int FindStrLen(char *s)
{
    int count = 0;
    for(; *s != '\0' ; s++)
        count++;
    return count;
}

int strendM(char *s, char *t)
{
    int slen = FindStrLen(s), tlen = FindStrLen(t);

    //moving the pointer where the t should start in s
    s += slen - tlen;

    for(; *s != '\0' && (*s) == (*t);s++, t++);

    if(*s == '\0' && *t == '\0')
        return 1;
    return 0;
}

int main(void)
{
    char s[MAXLEN];
    char t[MAXLEN];

    scanf("%s", s);
    scanf("%s", t);

    printf("%i\n", strendM(s, t));

    return 0;
}
