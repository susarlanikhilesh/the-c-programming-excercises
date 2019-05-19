/*
  Write a program to fold the long inputlines into multiple lines for
  nth column
  Constant nth column value : FOLDLEN : 10
  input1:first        second
  output1:first
          second
  input2:first second third
  output2:first
          second third
  input3:first
  output2:first

  TODO: Read FOLDLEN value from user(Dynamic)

  Extension : Fold every nth column
  Calculate FOLDLEN for n-length input line and fold every FOLDLEN
*/

#include<stdio.h>

//Max input line lenght
#define MAXLINE 1000
//N-th column to fold the long input line into two lines
#define FOLDLEN 10
//Macros to Calculate previous and next word after the FOLDLEN point
#define PREVWRD 0
#define NEXTWRD 1

//Read user input long line with MAXLINE length
int ReadInputLine(char source[])
{
    int len = 0;
    for(int c = 0; (c = getchar()) != EOF && c != '\n';)
    {
        source[len++] = c;
    }
    return len;
}

int FindWordIndex(char source[], int n, int foldLen, int comparetor)
{
    int i = foldLen;
    //Used when foldLen index falls between word
    int flag = 0;
    //Find previous word before foldLen value and replace it with \n
    while(source[i] == '\n' || source[i] == ' ' || source[i] == '\t')
        if(comparetor) //to find next word
            i++;
        else //to find the previous word
            i--;
    if(i == foldLen) //if the foldLen falls between word
    {
        if(comparetor) //find the start of that word, which acts as a nxtWordIdx
          while(source[i] != '\n' && source[i] != ' ' && source[i] != '\t')
          {
             i--;
             flag = 1;
          }
        else //find the previous word ending index, which acts as prevWordIdx
        {
          while(source[i] != '\n' && source[i] != ' ' && source[i] != '\t')
            i--;
          while(source[i] == '\n' || source[i] == ' ' || source[i] == '\t')
            i--;
        }
    }
    //As the index is at the non charaters like space/tab,
    //so to point it to the start of the next word we did ++
    if(flag == 1) ++i;
    //i is always pointing to ending or starting letter of the words
    return i;
}
//Simple shift whole input line after \n, breaking them into multiple lines
void ShiftNextWords(char source[], int pre, int nxt, int n)
{
    int i = pre;
    for(int j = nxt; j < n; i++, j++)
    {
        source[i] = source[j];
    }
    source[i] = '\0';
    return;
}

void Fold(char source[], int prevWordIdx, int nxtWordIdx, int n)
{
    //Breaks the long input line and places \n
    if(source[prevWordIdx + 1] != EOF || source[prevWordIdx + 1] != '\n')
        source[prevWordIdx + 1] = '\n';
    //Shifts the remaining next words besides \n
    ShiftNextWords(source, prevWordIdx + 2, nxtWordIdx, n);
    return;
}

//Logic to fold long input lines
void FoldLongLines(char source[], int n)
{
    /*
      Extension : Can Calculate FOLDLEN intervals here
      while(FOLDLEN < n)
        do something
        FOLDLEN += FOLDLEN
    */
    //This ensures to check out of bounds
    if(n <= FOLDLEN) return; //Can't fold if the input line is less than FOLDLEN
    /*
      find the previous word index which lies before FOLDLEN index
      finding previous word index helps us to place a new line
    */
    int prevWordIdx = FindWordIndex(source, n, FOLDLEN, PREVWRD);
    /*
      find the next word index which lies after FOLDLEN index
      finding next word index helps us to shift all the charaters
      after \n which is after the previous word
    */
    int nxtWordIdx = FindWordIndex(source, n, FOLDLEN, NEXTWRD);
    //passing the index's will simple do the need
    Fold(source, prevWordIdx, nxtWordIdx, n);
    return;
}

int main(void)
{
    char source[MAXLINE];
    int source_len = ReadInputLine(source);
    FoldLongLines(source, source_len);
    printf("%s", source);
    return 0;
}
