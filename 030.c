#include<stdio.h>
int main()
{
	long long n,x,s;
	long long sum = 0;
	n = 2;
	while(n < 1000 * 1000 ) {
		x = n;
		s = 0;
		while(x != 0) {
			s = s + (x%10)*(x%10)*(x%10)*(x%10)*(x%10);
			x = x/10;
		}
		if ( s == n ) {
			sum = sum + n;
			printf("%lld\n", n);
		}
		n++;
	}
	printf("%lld\n", sum);
	return 0;
}
