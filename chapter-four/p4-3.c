/*
    Given the basic framework, it's straightforward to extend the calculator.
    Add the modulus ( % ) operator and provisions for negative numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER 0
#define STACKMAXCAPACITY 100
#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE];
int stackPointer = 0;
double stack[STACKMAXCAPACITY];

/*
    Pushes the number read from the user input into stack,
    number resides in localBuffer variable
*/
void push(double f)
{
    //printf("%lf\n", f);
    //stack overflow check
	if(stackPointer < STACKMAXCAPACITY)
		stack[stackPointer++] = f; //insert number into stack
	else
		printf("error: stack full, can't push %lf\n", f);
    return;
}

//To print the elements in the stack
void StackTrace(void)
{
	printf("StackTrace\n");
	for(int i = stackPointer - 1; i >= 0; i--)
		printf("%lf\n", stack[i]);
	return;
}

//Pops out the last inserted element
double pop(void)
{
    //checking for underflow
	if(stackPointer > 0)
		return stack[--stackPointer];
	else
	{
		printf("error: stack empty\n");
		exit(1);
	}
}

//Checks if the last character is available, else requests for user input
int getch(void)
{
    /*
        checks if buffer pointer (bufp) is greater than 0
            then returns the last entered character after the number
        else
            requests a new character from user input

        Note: This helps us to save the last character after a digit in this program
            as the last character is a seperation from the number.
            It can be either a space or any non digit. We should save any non-digit
            as if it  is an operator then we should perform the operation on the
            numbers in the stack
    */
	if(bufp > 0)
        return buf[--bufp];
    int c = getchar();
    return c;
}

//This function helps us to save the last entered character, other than EOF
void ungetch(int c)
{
    //Checking buffer overflow
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
    /*
        saves the last character into the buffer.
        next time when user requests for input,
        getch check if the last character is valid or not,
            if not valid then the character is discarded from the buffer
            else it requests for new input
    */
		buf[bufp++] = c;
    return;
}

int getop(char localBuffer[])
{
	int i = 0, c = 0;
    /*
        Ignoring all the blank and tab spaces until reading a non blank character
        getch returns the last character if exits else requests for new input
        depending upone that we have to check the conditions and perform required
        operation
    */
	while((c = getch()) == ' ' || c == '\t');
    /*
        checking is the non blank character
            i)  is not a digit
            ii) is not . (which can be used to calculate fractions)
            iii)is not - (which can be used for negative numbers)
    */
	if(!isdigit(c) && c != '.' && c != '-')
    {
        //making the localBuffer empty, terminating it with null character
        localBuffer[0] = '\0';
        //returning the non blank and non digit character
        return c;
    }
    //checking if the character is a digit or - (for a negative number)
	if(isdigit(c) || c == '-')
    {
        //if negative number or operator
        if(c == '-')
        {
            localBuffer[i++] = '-';
            c = getch();
        }
        /*
            if negative sign and after the next character can be
                a number
                or negative sign was an operator

            if next character after negative sign is \n then return the operator
        */
        if(c != '\n')
        {
            while(isdigit(c)) //as long as it is a number
            {
                localBuffer[i++] = c;
                c = getch();
            }
        }
        else
        {
            //store the character which is mostly \n, this helps in next time user input and printing the result
            ungetch(c);
            return '-'; //- operation to be performed
        }
    }
	if(c == '.')
    {
        //if number integeral part is 0
        if(i == 0)
            localBuffer[i++] = '0';
        //append . for starting fractional part
        localBuffer[i++] = c;
        while(isdigit(c = getch())) //if the last read character was not a digit and . (fractional part)
            localBuffer[i++] = c;
    }
	localBuffer[i] = '\0'; //terminating the local string buffer
	if(c != EOF) //last read character was not a digit, so we have to save the digit for the next operation
		ungetch(c); //this function helps us to save the last character in buffer
	return NUMBER; //returning the macro indicating it is a number and convert the string value localBuffer into a number
}

int main()
{
	int type;
	double op2;
	char localBuffer[MAXOP];

	while((type = getop(localBuffer)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
                push(atof(localBuffer));
				break;
			case '+':
                /*
                    Reason for including braces is case statemets is case should
                    be followed by statements and declarations are not
                    statemets
                    Refer : https://stackoverflow.com/questions/46341364/label-can-only-be-used-as-part-of-a-statement-error
                */
                push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if(op2 != 0.0)
                    //in-built fmod which does float modulo
                    //not sure of the exact implementations for negative numbers
					push(fmod(pop(), op2));
				else
					printf("error: division by zero\n");
				break;
			case '\n':
				StackTrace();
				break;
			default:
				printf("error: unknown command %s\n", localBuffer);
				break;
		}
	}
	return 0;
}
