/*
    Print the horizontal histogram of frequency of letters(lowercase only)
    Note : Can store all the ascii values by using the frequency array to 255
*/
#include<stdio.h>

#define NLOWERCASELETTERS 26

void PrintBar(int n)
{
    for(int i = 0; i < n; i++)
        printf("-");
    n != 0 ? printf("\n") : printf(" ");
    return;
}

//for each letter print the graph using PrintBar
void PrintHorizontalHistogram(int lenOfWords[])
{
    for(int i = 0; i < NLOWERCASELETTERS; i++)
        PrintBar(lenOfWords[i]);
    return;
}

//Count each letter frequency
void CountLetterFreq(int letters[])
{
    for(int c = 0, state = 0; (c = getchar()) != EOF; )
    {
        if(c == '\n' || c == '\t' || c == '\b' || c == ' ')
            state = 0;
        else
            letters[c - 'a']++;
    }
    return;
}

int main(void)
{
    int letters[NLOWERCASELETTERS] = {0};
    CountLetterFreq(letters);
    PrintHorizontalHistogram(letters);
    return 0;
}
