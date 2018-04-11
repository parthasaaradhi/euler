#include<stdio.h>
long long isSquare(long long n) {
	long long x;
	x = n;
	while(!(n==x*x || (n>x*x && n<(x+1)*(x+1)))) {
		x = (x+(n/x))/2;
	}
	return (x*x==n)? x : 0;
}

int main()
{
	long long a,b,x,y,c,d;
	a = 1;
	while(a<2000) {
		x = (a*(3*a-1))/2;
		b = a+1;
		while(b<3000) {
			y = (b*(3*b-1))/2;
			c = isSquare(24*(x+y)+1);
			d = isSquare(24*(y-x)+1);
			if (c!=0 && d!=0 && c%6 == 5 && d%6==5) {
				printf("%lld : %lld : %lld : %lld : %lld : %lld\n", x, y, x+y, y-x, a, b);
				return 0;
			}
			b++;
		}
		a++;
	}
	return 0;
}
