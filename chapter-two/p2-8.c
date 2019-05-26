/*
    function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions.
*/
#include <stdio.h>

#define NBITS sizeof(unsigned int) * 8

unsigned int right(unsigned int x, unsigned int n)
{
    unsigned int r = x >> n;
    unsigned int l = x << (NBITS - n);
    return r ^ l;
}

int main(void)
{
    unsigned int x = 0, n = 0;
    scanf("%u %u", &x, &n);
    printf("%u\n", right(x, n));
	return 0;
}
