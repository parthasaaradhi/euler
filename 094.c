#include<stdio.h>

#define N 1000*1000*1000

long long is_perfect_square(long long n)
{
	long long a;
	a = n;
	while(a*a>=n)
	{
		if(a*a == n)
			return a;
		else
			a = (a+n/a)/2;
	}
	return -1;
}

int main()
{
	long long k,s,p;
	p=0;
	for(k=1;k<=N;k++)
	{
		s = is_perfect_square(3*k*k+1);
		if(s!=-1 && s%3!=0 && s<=N/2+1 && s!=4 && s!=2)
		{
			if(s%3==1)
			{
				printf("%lld %lld %lld\t ", 2*(s-1)/3+1, 2*(s-1)/3+1, 2*(s-1)/3+2);
			} else
			{
				printf("%lld %lld %lld\t ", 2*(s-2)/3+1, 2*(s-2)/3+1, 2*(s-2)/3);
			}
			printf("%lld\n", s%3==1? 2*s+2 : 2*s-2);
			p = p + (s%3==1? 2*s+2 : 2*s-2);
		}
	}
	printf("%lld\n", p);
	return 0;
}
