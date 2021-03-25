#include<stdio.h>

long long no_divisors(long long n)
{
	long long i,x,s;
	s = 1;
	i = 2;
	while(n!=1)
	{
		x=0;
		while(n%i == 0)
		{
			x++;
			n=n/i;
		}
		s = s*(x+1);
		i++;
	}
	return (s+1)/2;
/*
	for(i=1;i<=n;i++)
		s = s + ((n%i==0)? 1 : 0);
	return (s+1)/2;*/
}

int main()
{
	long long n,x;
	n=1;x=0;
	while(x<4*1000*1000)
	{
		x = no_divisors(n*n);
		printf("%lld : %lld\n", n, x);
		n++;
	}
	printf("%lld\n", n-1);
	return 0;
}
