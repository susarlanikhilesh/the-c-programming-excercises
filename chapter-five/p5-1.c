/*
    As written, getint treats a + or - not followed by a digit as a valid representation of zero.
    Fix it to push such a character back on the input.
*/

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 1
#define SIZE    100

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
    int n = 0, array[SIZE] = {0}, getint(int *);
    for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++);
    for(int i = 0; i < n; i++)
        printf("%i ", array[i]);
    return 0;
}

int getint(int *pn)
{
    int c = 0, sign = 1;

    while(isspace(c = getch()));
    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
    {
        if(!isdigit(c = getch()))
        {
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if(c != EOF) ungetch(c);
    return c;
}
