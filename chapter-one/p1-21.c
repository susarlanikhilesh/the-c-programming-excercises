/*
	Program to entab that replaces strings of blanks with min number
	of tabs and spaces to acheive the same spacing
*/
#include <stdio.h>

#define MAXLINE  1000
#define TABSPACE 4

int GetLine(char line[])
{
		int len = 0;
		for(int c = 0; (c = getchar()) != EOF;)
		{
				if(c == '\n')
				{
						line[len] = '\0';
						break;
				}
				line[len] = c;
				len++;
		}
		return len;
}

int Entab(char source[], target[], int n)
{
    /*
			TODO :To replace spaces with tabs and spaces as required
    */
}

void Print(char line[], int n)
{
		for(int i = 0; i < n; i++)
			printf("%c", line[i]);
		printf("\n");
		return;
}

int main(void)
{
  char source[MAXLINE];
  char target[MAXLINE * TABSPACE];
  int source_len = 0;
  source_len = GetLine(source);
  int target_len = Entab(source, source_len);
  Print(target, target_len);
}
