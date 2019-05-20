/*
    Remove Comments from a C program
    Two types of Commenting style

    Note: Comments CAN'T be nested
*/
#include<stdio.h>

//Max input line length
#define MAXLINE 1000

//to determine is a comment is within a string or not
#define NO  0
#define YES 1

//Read user input long line with MAXLINE length
int ReadInputLine(char source[])
{
    int len = 0;
    for(int c = 0; (c = getchar()) != EOF;)
    {
        source[len++] = c;
    }
    return len;
}

void RemoveSingleLineComment(char source[], int n, int i)
{
    /*
        Testcase1:
        //comment in a new line
        Testcase2:
        appears at the last of the line //comment starts and ends
    */

    //j points to first slash in the comment
    int j = i;

    if(!(j == 0 || source[j - 1] == '\n')) //Testcase2 condition check
    {
        source[j++] = '\n';
        ++i;
    }
    /*
        iterate till end of the comment
        Testcase1: Can have multiple lines below
        Testcase2: Can be the last line of the program
    */
    while(i < n && source[i] != '\n')
        ++i;

    //if not the last line of the program
    if(i < n)
    {
        //copy rest of the program/string, copy in-place of the array
        int k = (++i);
        while(k < n)
          source[j++] = source[k++];
        source[j] = '\0';
    }
    else //last line of the program which is a comment, so just end the line
      source[i] = '\0';
    return;
}

void RemoveMultiLineComment(char source[], int n, int i)
{
    /*
        Testcase1:
          Appears in single line
        Testcase2:
          Starts at the ending of a line, appears in multiple lines
          spanning across multi lines
        Testcase3:
          Appears end of the program
    */
    //j points to first slash in the comment
    int j = i;

    if(!(j == 0 || source[j - 1] == '\n')) //Testcase2 condition check
    {
        source[j++] = '\n';
        ++i;
    }

    /*
        Check out of bounds
        Check if i'th && i + 1 index is matching comment pattern
        If any one index match fails we should still continue
        else we reached the end of the comment
    */
    while(i + 1 < n && (source[i] != '*' || source[i + 1] != '/'))
        ++i;

    //i is point at the * in the comment ending
    if(i + 2 < n)
    {
        //mark i at the next char index in the string/program
        i += 2;

        //copy rest of the program/string, copy in-place of the array
        int k = (++i);
        while(k < n)
          source[j++] = source[k++];
        source[j] = '\0';
    }
    else //last line of the program which is a comment, so just end the line
      source[i] = '\0';
    return;
}

void RemoveComments(char source[], int n)
{
    int isString = NO;
    for(int i = 0; i < n; i++)
    {
        /*
            Comments can lie under strings
            Testcase1: char s[] = "//this is not a comment";
            Testcase2: printf("//this is also not comment");

            Testcase1: char s[] = "/*this is not a comment* /";
            Testcase2: printf("/*this is also not comment* /");
        */
        if(source[i] == '"')
        {
            if(!isString) isString = YES;
            else isString = NO;
        }

        /*
          Check out of bounds before accessing: i + 1 < n
          Check if the i'th index and i + 1 index are matching with comment pattern
          Check if the index does not lie within a string (double quotes)
        */
        if(i + 1 < n && (source[i] == '/' && source[i + 1] == '/') && !isString){
              RemoveSingleLineComment(source, n, i);
              //this is to bring back the index and check again if the next line was a comment
              //cryptic
              --i;
        }
        else if(i + 1 < n && (source[i] == '/' && source[i + 1] == '*') && !isString){
            RemoveMultiLineComment(source, n, i);
            //this is to bring back the index and check again if the next line was a comment
            //cryptic
            --i;
        }
    }
    return;
}

int main(void)
{
    char source[MAXLINE];
    int source_len = ReadInputLine(source);
    /*
      Comments are:
       Single line comments : //
       Multi line comments : /** /
    */
    RemoveComments(source, source_len);
    printf("%s\n", source);
    return 0;
}
