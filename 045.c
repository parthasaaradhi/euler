#include<stdio.h>
long long mysqrt(long long n) {
	long long x;
	x = n;
	while(!(n==x*x || ((n>x*x) && (n<(x+1)*(x+1))))) {
		x = (x + (n/x))/2;
	}
	return (x*x == n)? x : 0;
}
int main()
{
	long long n = 144;
	long long s,b;
	while(1) {
		s = n*(2*n-1);
		b = mysqrt(1+24L*s);
		if(b!=0 && b%6==5) {
			printf("%lld\n", s);
			return 0;
		}
		n++;
	}
	return 0;
}
