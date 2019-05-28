/*
    Adapt the ideas of printd to write a recursive version of itoa ;
    that is, convert an integer into a string by calling a recursive routine.
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 100

void itoaRecursive(char s[], int n, int idx)
{
    if(n <= 0){
        s[idx] = '\0';
        return;
    }
    s[idx] = (n % 10) + '0';
    itoaRecursive(s, n / 10, ++idx);
    return;
}

void reverse(char s[], int start, int end)
{
    if(start >= end) return;
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    reverse(s, ++start, --end);
    return;
}

int main(void)
{
    int n = 0, idx = 0;
    scanf("%i", &n);

    char s[MAXLEN];
    itoaRecursive(s, n, idx);
    reverse(s, 0, strlen(s) - 1);

    printf("%s\n", s);

    return 0;
}
