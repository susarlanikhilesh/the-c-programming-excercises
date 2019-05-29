/*
    Rewrite readlines to store lines in an array supplied by main , rather than calling alloc to maintain storage.
*/
#include <stdio.h>      //standard input, output
#include <string.h>     //string comparison

#define MAXLINES    1000    //maximum lines we can have
#define MAXLEN      100     //maximum line len

//swap two pointers of character array
void swap(char *lptr[], int i, int j)
{
    char *temp;
    temp = lptr[j];
    lptr[j] = lptr[i];
    lptr[i] = temp;
    return;
}

//sort a character array of pointers based on alphabetical order
void qsort(char *lptr[], int left, int right)
{
    int i = 0, last = 0;
    void swap(char *lptr[], int i, int j);

    if(left >= right)
        return;
    swap(lptr, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
    {
        if(strcmp(lptr[i], lptr[left]) < 0)
            swap(lptr, ++last, i);
    }
    swap(lptr, left, last);
    qsort(lptr, left, last - 1);
    qsort(lptr, last + 1, right);
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

int main(void)
{
    char *lineptr[MAXLINES];

    int n = 0;
    char localBuffer[MAXLINES][MAXLEN];
    if((n = readLines(lineptr, localBuffer, MAXLINES)) > 0){
        qsort(lineptr, 0, n - 1);
        writeLines(lineptr, n);
    }
    else
        printf("No lines read\n");
    return 0;
}
