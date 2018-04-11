#include<stdio.h>
int main()
{
	long long N = 600851475143;
	long long x = 2;
	while(N != x)
	{
		while(N%x == 0) {
			N = N/x;
		}
		x = x + 1;
	}
	printf("%lld\n", x);
	return 0;
}
