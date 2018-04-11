#include<stdio.h>
int main()
{
	long long N = 4 * 1000 * 1000;
	long long x = 1;
	long long y = 1;
	long long temp;
	int z = 0;
	// Here x = f(3*n+5), where f(3n+2) is the last even number less than N.
	while(x < N || (z+2)%3 != 0) {
		temp = x;
		x = x + y;
		y = temp;
		z = z + 1;
	}
	printf("%lld\n", (y-1)/2);
	return 0;
}
