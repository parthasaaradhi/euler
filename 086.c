#include<stdio.h>
#define M 616
long long is_perfect_square(long long n)
{
	long long a;
	a = n;
	while(a*a>=n)
	{
		if(a*a == n)
			return 0;
		else
			a = (a+n/a)/2;
	}
	return 1;
}

int main()
{
	long long a,x;
	long long s;
	s=0;
	a=2;
	while(s<1000*1000)
	{
		for(x=3;x<=2*a;x++)
		{
			if(is_perfect_square(a*a+x*x) == 0)
			{
				s = s + ((x<=a)? x/2 : 1 + (a - ((x+1)/2)));
			}
		}
		a++;
	}
	printf("Final CountDown: %lld  reached at :%lld\n", s, a-1);
	return 0;
}
