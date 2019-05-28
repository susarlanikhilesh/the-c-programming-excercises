/*
    Q:
    Our getch and ungetch do not handle a pushed-back EOF correctly.
    Decide what their properties ought to be if an EOF is pushed back, then implement your design.

    A:
    The reason why the code in K&R can't handle EOF is because it is defined as follows:
    #define EOF -1
    i.e. its value is negative and a char array can't hold a negative value.
    Change the buffer type to int and the problem is solved.
*/
