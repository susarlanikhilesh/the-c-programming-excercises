/*
    Reverse polish calculator using command line arguments

    Note :
    while reading command line arguments, when reading the multiplication
    operator, it was acting like a pattern matcher and reading the contents of
    the folder. To aviod use escape sequence.
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//Can't have numbers more than 100
#define MAXLEN      100
#define SUPPORT     "+,-,*,/,%\n"

int stack[MAXLEN];
int sp = 0;

void push(int x)
{
    printf("%i\n", x);
    stack[sp++] = x;
    return;
}

int pop()
{
    return stack[--sp];
}

int main(int argc, char const *argv[])
{
    while(*(++argv))
    {
        if(isdigit((*argv)[0]))
            push(atoi(*argv));
        else
        {
            int op2 = 0;
            int c = (*argv)[0];
            switch (c) {
                case '*': push(pop() * pop()); break;
                case '+': push(pop() + pop()); break;
                case '-': op2 = pop(); push(pop() - op2); break;
                case '/': op2 = pop(); push(pop() / op2); break;
                case '%': op2 = pop(); push(pop() % op2); break;
                default: printf(SUPPORT);
            }
        }
    }
    return 0;
}
