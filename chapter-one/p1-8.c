/*
  Program to count blanks, tabs, newlines
*/
#include<stdio.h>

int main(void)
{
    int c = 0, nblanks = 0, ntabs = 0, nnewlines = 0;
    /*
      return type of getchar is int.
      return value should be big enough to hold EOF value(-1)
      so the variable is of int not char
    */
    for(;(c = getchar()) != EOF;)
    {
        if(c == ' ')
            ++nblanks;
        else if(c == '\t')
            ++ntabs;
        else if(c == '\n')
            ++nnewlines;
    }
    printf("blanks = %d\ntabs = %d\nnewlines = %d\n", nblanks, ntabs, nnewlines);
    return 0;
}
