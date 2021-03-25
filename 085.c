#include<stdio.h>

long long absol(long long x, long long y)
{
	return x < y ? y-x : x-y;
}

int main()
{
	long long m,n,s;
	for(n=1;n<100;n++)
	{
		for(m=n+1;m<100;m++)
		{
			s=m*n*(m+1)*(n+1)/4;
			printf("%lld : %lld\n",absol(s, 2*1000*1000), m*n);
		}
	}
	return 0;
}
