/*
    Return the index position from s1 if it matches with the char in s2(first such match)
*/
#include<stdio.h>

#define MAX_LEN 10

char s1[MAX_LEN];
char s2[MAX_LEN];

int idx = -1;

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

//Check if s1 any char matching s2 return s1 first matching char index
int Any(void)
{
    for(int i = 0; s1[i] != '\0'; i++)
        if(CheckIfExistsInS2(s1[i])) return i;
    return -1;
}

int main(void)
{
    extern int idx;
    ReadInput();
    idx = Any();
    printf("position = %i\n", idx);
    return 0;
}
