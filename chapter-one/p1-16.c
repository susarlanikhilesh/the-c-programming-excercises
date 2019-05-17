/*
    p1-16.c : Print the longest line in the input lines
    p1-17.c : Print the longest line length greater than 80 in the input lines
    p1-18.c : Remove the blanks and tabs from each input line(actually trailing blanks and tabs)
    p1-19.c : Reverse the char of each line of the input lines

    Note: Revisit and refactor the code
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

char* Copy(char longLine[], int len)
{
    int i = 0;
    char *line = (char*)malloc(len * sizeof(char));
    for(i = 0; i < len; i++)
        line[i] = longLine[i];
    line[i] = '\0';
    return line;
}

int GetLine(char longLine[])
{
    int c = 0;
    int i = 0;
    int iter = 1;
    while((c = getchar()) != EOF)
    {
        if(i > 100 * iter)
        {
            iter*=10;
            longLine = (char*)realloc(longLine, 100 * iter);
        }
        /*p1-18.c*/
        if(c != '\n' && c != '\t' && c != '\b' && c != ' ')
            longLine[i] = c;
        i++;
    }
    longLine[i] = '\0';
    return i;
}

void Print(int max, char longestLine[])
{
    for(int i = 0; i < max; i++)
        printf("%c", longestLine[i]);
    printf("\n");
    return;
}

char *ReverseLongLine(char longLine[], int len)
{
    for(int i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = longLine[i];
        longLine[i] = longLine[j];
        longLine[j] = temp;
    }
    return longLine;
}

int main(void)
{
    int max = INT_MIN;
    char *longLine = (char*)malloc(100 * sizeof(char));
    char *longestLine;
    int len = 0;
    while((len = GetLine(longLine)) > 0)
    {
        if(max < len)
        {
            longestLine = Copy(longLine, len);
            max = len;
            /*p1-17.c*/
            if(max >= 80 /*|| 1*/) //to print every line uncomment
                Print(max, longestLine);
        }
        /*p1-19.c*/
        char *revLine = ReverseLongLine(longLine, len);
        Print(len, revLine);
    }
    return 0;
}
