/*
    Reverse a string in recursive way in place method
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 100

void swap(char s[], int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return;
}

void reverse(char s[], int start, int end)
{
    if(start >= end) return;
    swap(s, start, end);
    reverse(s, ++start, --end);
    return;
}

int main(void)
{
    char s[MAXLEN];
    scanf("%[^\n]s", s);
    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);
    return 0;
}
