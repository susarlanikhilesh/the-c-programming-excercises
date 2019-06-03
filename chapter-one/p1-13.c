/*
  Print histogram of lengths of words in input.
  Horizontal histogram.
  Verticcal histogram.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

//Maximum words to print histogram
#define MAXWORDS 1000

//To count each word length and count number of words
int CountWordLen(int lenOfWords[])
{
    /*
     Initialized word count as -1, so as fit into the array index of
     lenOfWords
    */
    int wc = -1;
    for(int c = 0, len = 0, state = 0;(c = getchar()) != EOF;)
    {
        if(c == '\n' || c == '\t' || c == '\b' || c == ' ' && wc != -1)
        {
            lenOfWords[wc] = len;
            len = 0;
            state = 0;
        }
        else if(state == 0)
        {
            state = 1;
            ++len;
            ++wc;
        }
        else
            ++len;
    }
    return wc + 1;
}

void PrintBar(int n)
{
    for(int i = 0; i < n; i++)
        printf("-");
    n != 0 ? printf("\n") : printf(" ");
    return;
}

void PrintHorizontalHistogram(int lenOfWords[], int numberOfWords)
{
    //for every words print bars till its length using PrintBar function
    for(int i = 0; i < numberOfWords; i++)
        PrintBar(lenOfWords[i]);
    return;
}
//GetMaxLenOfWords : returns max longest word length
int GetMaxLenOfWords(int lenOfWords[], int n)
{
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
      if(lenOfWords[i] > max)
        max = lenOfWords[i];
    return max;
}

void PrintVerticalBar(int lenOfWords[], int n, int maxLen)
{
    //maxLen of the word would have the bar print on the first line
    while(maxLen)
    {
        //traverse the whole array to see if any word has same len
        for(int j = 0; j < n; j++)
        {
            //if match then print
            if(lenOfWords[j] == maxLen)
            {
                printf("|");
                --lenOfWords[j];
            }
            //else print space, might be a smaller bar
            else
                printf(" ");
            printf(" ");
        }
        printf("\n");
        //do until you print every len from max to 0
        --maxLen;
    }
    return;
}

void PrintVerticalBarNotUsing(int lenOfWords[], int n, int maxLen)
{
    //create a double dimension matrix
    //number of rows : max longest length of all the words
    char *mat[maxLen];
    //number of columns : number of words entered
    for (int i = 0; i < maxLen; i++)
       mat[i] = (char*)malloc(n * sizeof(char));

    //fill the matrix vertically, which is easy
    for(int i = 0; i < n; i++)
    {
        //fillFrom : calcuates from where the vertical bars has to be
        //           placed for the particular word
        int fillFrom = maxLen - lenOfWords[i];
        //fill the smaller length words with null till the start of the
        //word
        for(int j = 0; j < fillFrom; j++)
            mat[j][i] = NULL;
        //later fill the bars
        for(int j = fillFrom; j < maxLen; j++)
            mat[j][i] = '|';
    }

    //print the vertical histogram.
    //nothing than printing a matrix which is filled with vertical bars
    //can be moved to another function
    for(int i = 0; i < maxLen; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%c\t", mat[i][j]);
        }
        printf("\n");
    }
    return;
}

void PrintVerticalHistogram(int lenOfWords[], int numberOfWords)
{
    //maxLen to calcuate the max heigt the vertical histogram draws
    int maxLen = GetMaxLenOfWords(lenOfWords, numberOfWords);
    PrintVerticalBar(lenOfWords, numberOfWords, maxLen);
    return;
}

int main(void)
{
    //To store each word length to print histogram
    int lenOfWords[MAXWORDS] = {0};
    //Count number of words, useful for printing histograms
    int wc = CountWordLen(lenOfWords);

    printf("Number of words : %d\n", wc);

    PrintHorizontalHistogram(lenOfWords, wc);
    printf("\n\n");
    PrintVerticalHistogram(lenOfWords, wc);
    return 0;
}
