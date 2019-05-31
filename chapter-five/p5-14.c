/*
    Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order.
    Be sure that -r works with -n
*/
#include <stdio.h>      //standard input, output
#include <string.h>     //string comparison
#include <stdlib.h>

#define MAXLINES    1000    //maximum lines we can have
#define MAXLEN      100     //maximum line len
#define USAGE       "qsort -rn\n"

void swap(void *lptr[], int i, int j)
{
    void *temp;
    temp = lptr[j];
    lptr[j] = lptr[i];
    lptr[i] = temp;
    return;
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)         return -1;
    else if(v1 > v2)    return 1;
    else                return 0;
}

void qsortM(void *lptr[], int left, int right, int (*cmp)(void *, void *), int reverseFlag)
{
    int i = 0, last = 0;
    void swap(void *lptr[], int i, int j);

    if(left >= right)
        return;
    swap(lptr, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
    {
        if(reverseFlag)
        {
            if((*cmp)(lptr[left], lptr[i]) < 0)
                swap(lptr, ++last, i);
        }
        else
        {
            if((*cmp)(lptr[i], lptr[left]) < 0)
                swap(lptr, ++last, i);
        }
    }
    swap(lptr, left, last);
    qsortM(lptr, left, last - 1, cmp, reverseFlag);
    qsortM(lptr, last + 1, right, cmp, reverseFlag);
    return;
}

//to display the sorted lines
void writeLines(char *lptr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%s\n", lptr[i]);
    return;
}

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

//to store lines in the lineptr
int readLines(char *lptr[], char localBuffer[][MAXLEN], int max)
{
    int len = 0, n = 0;

    while((len = getLine(localBuffer[n], max)) > 0)
        lptr[n++] = localBuffer[n];
    return n;
}

int main(int argc, char *argv[])
{
    int numeric = 0, reverse = 0;

    if(argv[1] == NULL) numeric = reverse = 0;
    else if(strcmp(argv[1], "-nr") == 0 || strcmp(argv[1], "-rn") == 0)
        numeric = reverse = 1;
    else if(strcmp(argv[1], "-n") == 0)
        numeric = 1;
    else if(strcmp(argv[1], "-r") == 0)
        reverse = 1;

    char *lineptr[MAXLINES];

    int n = 0;
    char localBuffer[MAXLINES][MAXLEN];
    if((n = readLines(lineptr, localBuffer, MAXLINES)) > 0)
    {
        int (*p)(void*, void*);
        if(numeric) p = &numcmp;
        else        p = &strcmp;
        if(p != NULL)
            qsortM((void**)lineptr, 0, n - 1, p, reverse);
        writeLines(lineptr, n);
    }
    else
        printf("No lines read\n");
    return 0;
}
