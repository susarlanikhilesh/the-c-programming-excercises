/*
	Set n bits starting from position p in y into x
	Sol1 : iterate through all the bits till position p and check bits
*/
#include <stdio.h>
#include <math.h>

#define NBITS sizeof(unsigned int) * 8

unsigned int SetBits(unsigned int x,unsigned int p,unsigned int n,unsigned int y)
{
	int countBits = 0;
	unsigned int res = 0;
	for(int i = 0; i < NBITS; i++)
	{
		int bit = 0;
		if(countBits >= (p - n + 1) && countBits <= p)
			bit = y & 1;
		else
			bit = x & 1;

		res +=  (bit * pow(2, i));

		x >>= 1;
		y >>= 1;
		countBits++;
	}
	return res;
}

int main(void)
{
	unsigned int x = 0;
	unsigned int y = 0;
	scanf("%u %u", &x, &y);

	unsigned int p = 0;
	unsigned int n = 0;
	scanf("%u %u", &p,&n);

	unsigned int temp = x;

	x = SetBits(x, p, n, y);
	printf("%u\n", x);
	temp = InvertBits(temp, p, n);
	printf("%u\n", temp);
	return 0;
}
