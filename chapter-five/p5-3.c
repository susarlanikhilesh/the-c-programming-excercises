/*
    Write a pointer version of the function strcat that we showed in Chapter 2:
    strcat(s,t) copies the string t to the end of s .
*/
#include <stdio.h>

#define MAXLEN 1000

void strcatM(char *s, char *t)
{
    for(; *s != '\0' ; s++);
    for(; *t != '\0' ; )
        *s++ = *t++;
    return;
}

int main(void)
{
    char s[MAXLEN];
    char t[MAXLEN];
    scanf("%s", s);
    scanf("%s", t);
    strcatM(s, t);
    printf("%s\n", s);
    return 0;
}
