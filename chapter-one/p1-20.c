/*
		Program to detab that replaces tab with proper number of blank spaces
*/
#include<stdio.h>
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
//Replaces each tab with number of TABSPACE values.
int Detab(char source[], char target[], int n)
{
		//Count helps in to adjust the space lengths with tabs
		//when continuously appeared
		int j = 0, count = 1;
		for(int i = 0; i < n; i++, j++)
		{
				if(source[i] == '\t')
				{
						for(int k = 0; k < count * TABSPACE; k++)
								target[j++] = ' ';
						--j;
						count = 2;
				}
				else
				{
						target[j] = source[i];
						count = 1;
				}
		}
		return j;
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
		int target_len = Detab(source, target, source_len);
		Print(target, target_len);
}
