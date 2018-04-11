#include<stdio.h>
int main()
{
	long long a,b,c;
	long long st=0;
	for(a=3;a<333;a++) {
		st = a;
		if (a <= 250)
			st = 501 - a;
		for(b=st;b<499 && (b+a)>500;b++) {
			c = 1000 - a - b;
			if (c*c == (a*a + b*b)) {
				printf("%lld\n", a*b*c);
				return 0;
			}
		}
	}
	return 0;
}
