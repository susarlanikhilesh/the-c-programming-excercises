/*
    tolower function using conditional expression instead of if-else
*/
#include<stdio.h>

#define MAX_LEN 10

char s[MAX_LEN];

//Read two strings as input
void ReadInput(void)
{
    extern char s[];
    scanf("%s", s);
    return;
}

void ConvertToLower(void)
{
    for(int i = 0; s[i] != '\0'; i++)
        s[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] + ('a' - 'A') : s[i];
    return;
}

int main(void)
{
    ReadInput();
    ConvertToLower();
    printf("%s\n", s);
    return 0;
}
