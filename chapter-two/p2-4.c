/*
    Squeeze function which deletes s1 char, which are there in s2
*/
#include<stdio.h>

#define MAX_LEN 10

char s1[MAX_LEN];
char s2[MAX_LEN];

//Read two strings as input
void ReadInput(void)
{
    scanf("%s", s1);
    scanf("%s", s2);
    return;
}

//Check if character from s1 exists in string s2
int CheckIfExistsInS2(char c)
{
    extern char s2[];
    for(int i = 0; s2[i] != '\0'; i++)
        if(s2[i] == c)
            return 1;
    return 0;
}

//remove the char from s1 in index and shift the rest of the char in the string
void RemoveAndShift(int idx)
{
    extern char s1[];
    int i = idx;
    for(int j = i + 1; s1[j] != '\0'; i++, j++)
        s1[i] = s1[j];
    s1[i] = '\0';
    return;
}

//for every char in s1 check if it exists in s2 and RemoveAndShift if exists
void Squeeze(void)
{
    extern char s1[];
    for(int i = 0; s1[i] != '\0';)
        if(CheckIfExistsInS2(s1[i]))
            RemoveAndShift(i);
        else
            ++i;
    return;
}

int main(void)
{
    ReadInput();
    Squeeze();
    printf("s1 = %s\n", s1);
    return 0;
}
