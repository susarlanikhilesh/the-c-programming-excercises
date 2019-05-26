/*
	Invert n bits starting from position p in x
	Sol1 : iterate through all the bits till position p and invert bits
*/
#include <stdio.h>
#include <math.h>

#define NBITS sizeof(unsigned int) * 8

//0010 0010 1010 1100
//0000 1101 1010 1100

unsigned int InvertBits(unsigned int x,unsigned int p,unsigned int n)
{
	int countBits = 0;
	unsigned int res = 0;
	for(int i = 0; i < NBITS; i++)
	{
		unsigned int bit = 0;
		if(countBits >= (p - n + 1) && countBits <= p)
			bit = (x ^ 1) & 1;
		else
			bit = x & 1;

		res +=  (bit * pow(2, i));

		x >>= 1;
		countBits++;
	}
	return res;
}

int main(void)
{
	unsigned int x = 0;
	scanf("%u", &x);

	unsigned int p = 0;
	unsigned int n = 0;
	scanf("%u %u", &p,&n);

	x = InvertBits(x, p, n);
	printf("%u\n", x);
	return 0;
}
