#include<stdio.h>

long long int collatz(long long int n)
{
	if(n==1)
		return 1;
	if(n%2==0)
		return 1+collatz(n/2);
	else
		return 1+collatz(3*n+1);
}

int main()
{
	long long int i,x,m,t;
	x = 0;
	m = 0;
	for(i=1;i<1000*1000;i++)
	{
		t = collatz(i);
		if(t>m)
		{
			m = t;
			x = i;
		}
		//printf("%lld : %lld\n", i, collatz(i));
	}
	printf("%lld\n", x);
	return 0;
}
