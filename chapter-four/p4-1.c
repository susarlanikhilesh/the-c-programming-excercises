/*
    Function to return the position of rightmost occurrence of t in s else -1;
    strrindex(s, t);
*/
#include<stdio.h>

#define MAXLEN 1000

char pattern[] = "are";

int GetLine(char l[], int max)
{
    int i = 0, c = 0;
    for(;i < max && (c = getchar()) != '\0' && c != '\n';)
        l[i++] = c;
    if(c == '\n') l[i++] = '\n';
    l[i] = '\0';
    return i;
}

int StrRIndex(char l[], char p[])
{
    int i = 0;
    int index = -1;
    for(; l[i] != '\0'; i++)
    {
        int k = 0;
        for(int j = i;p[k] != '\0' && l[j++] == p[k++];)
        if(k != 0 && p[k] == '\0') index = i;
    }
    return index;
}

int main(void)
{
    char line[MAXLEN];
    while(GetLine(line, MAXLEN) > 0)
    {
        int idx = StrRIndex(line, pattern);
        printf("%i\n", idx);
    }
    return 0;
}
