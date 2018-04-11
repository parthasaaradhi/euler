#include<stdio.h>
int main()
{
	unsigned long long n,M,s,i,x;
	s = 0;
	M = 10000000000;
	n = 1;
	while(n<1000)
	{
		i = n-1;
		x = n;
		while(i!=0)
		{
			x = (x * n)%M;
			i--;
		}
		s = (s + x)%M;
		n++;
	}
	printf("%lld\n", s);
	return 0;
}
