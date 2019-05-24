/*
    Write a loop equivalent to for loop without using && and ||
*/

#include<stdio.h>

#define MAX_LINE_LEN 10

int main(void)
{
    //&& can be replaced by * as if one of the value is zero then everything goes to 0 which is false
    for(int i = 0, c = 0;(i < MAX_LINE_LEN - 1) * ((c = getchar()) != '\n') * (c != EOF);i++)
        putc(c, stdout);
    //|| can be replaced by + as if all the values tend to be zero then it tends to be false
    for(int i = 0, c = 0;(i < MAX_LINE_LEN - 1) + ((c = getchar()) != '\n');i++)
        putc(c, stdout);
    return 0;
}
