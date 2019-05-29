/*
    As written, getint treats a + or - not followed by a digit as a valid representation of zero.
    Fix it to push such a character back on the input.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE     1
#define SIZE        100
#define TEMPSIZE    1000

int bufp = 0;
char buf;

//Checks if the last character is available, else requests for user input
int getch(void)
{
	if(bufp > 0)
	{
		bufp--;
		return buf;
	}
    int c = getchar();
    return c;
}

//This function helps us to save the last entered character, other than EOF
void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
    {
        buf = c;
		bufp++;
    }
    return;
}


int main(void)
{
    double array[SIZE] = {0};
    int n = 0, getfloat(double *);
    for(n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);
    for(int i = 0; i < n; i++)
        printf("%lf ", array[i]);
    return 0;
}

int getfloat(double *pn)
{
    char localBuffer[TEMPSIZE];
    int c = 0, sign = 1;
    int idx = 0;

    while(isspace(c = getch()) || c == '\t');

    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
        return 0;

    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-')
    {
        localBuffer[idx++] = c;
        c = getch();
    }
    if(c != '.')
    {
        for(; isdigit(c); c = getch())
            localBuffer[idx++] = c;
    }
    if(c == '.')
    {
        localBuffer[idx++] = '.';
        c = getch();
        for(; isdigit(c); c = getch())
            localBuffer[idx++] = c;
    }
    localBuffer[idx] = '\0';
    *pn = (double)(sign * atof(localBuffer));
    if(c != EOF) ungetch(c);
    return c;
}
