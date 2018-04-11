#include<stdio.h>
int main()
{
	long long n,r,p,s;
	for(n=23;n<101;n++)
	{
		p = 1;
		r = 0;
		while(p <= 1000*1000) {
			p = ((n-r)*p)/(r+1);
			r++;
		}
		s = s + n + 1 - 2*r;
		//printf("%lld %lld\n", n, n+1-2*r);

	}
	printf("%lld\n", s);
	return 0;
}
