/*
    Write a routine ungets(s) that will push back an entire string onto the input.
    Should ungets know about buf and bufp , or should it just use ungetch ?
*/

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

void ungets(char s[])
{
    for(int i = 0; s[i] != '\0'; i++)
        ungetch(s[i]);
    return;
}
