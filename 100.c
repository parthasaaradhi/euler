#include<stdio.h>

int main()
{
	long long n = 1000000000000;
	long long x,y,z,w,s,t;
	int i = 0;
	x = 29;
	y = 41;
	z = 169;
	w = 239;
	while(i<1)//w<2*n-1)
	{
		i++;
		s = z;
		t = w;
		z = x*s+2*y*t;
		w = x*t+y*s;
	}
	s = (z+1)/2;
	t = (w+1)/2;
	printf("%lld\n", (z+1)/2);
	printf("%lld\n", (w+1)/2);
	printf("%lld\n", (s*(s-1))/(t*(t-1)));
	return 0;
}
