/*
    Write the program tail, which prints the last n lines of its input.
    By default, n is 10, say, but it can be changed by an optional argument,
    so that tail -n prints the last n lines.
    The program should behave rationally no matter how unreasonable the input or
    the value of n. Write the program so it makes the best use of available storage;
    lines should be stored as in the sorting program of Section 5.6,
     not in a two-dimensional array of fixed size.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXLINES    1000
#define MAXLEN      100
#define USAGE       "tail -num\n"

//to read a line from user
int getLine(char *l, int m)
{
    int i = 0;
    for(; i < m; i++)
    {
        int c = getchar();
        if(c == '\n' || c == EOF)
            break;
        l[i] = c;
    }
    l[i] = '\0';
    return i;
}

int main(int argc, char const *argv[])
{
    char *tailptr[MAXLINES];

    if(argc < 1 || argc > 2) printf(USAGE);
    else
    {
        int i = 0;
        char *line = (char*)malloc(sizeof(char) * MAXLEN);
        while(getLine(line, MAXLEN))
        {
            tailptr[i++] = line;
            line = (char*)malloc(sizeof(char) * MAXLEN);
        }

        int n = 10; //default lines
        if(argc != 1)
            n = atoi(*++argv) * -1;

        int end = i;
        i = (end < n) ? 0 : end - n;

        while(i < end)
            printf("%s\n", tailptr[i++]);
    }
    return 0;
}
