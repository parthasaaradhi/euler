#include<stdio.h>
int main() {
	long long x,y,a,b,i,p,q;
	x = 2; y = 1; p=9;q=4;i=0;
	while(i<15) {
		//printf("%lld %lld\n", 3*x+5*y,x+3*y);
		//printf("%lld %lld\n", 2*x, 2*y);
		//printf("%lld %lld\n", p+5*q, p+q);
		if((3*x+5*y-1)%5==0) {
			i++;
			if(i==15) {
				printf("%lld\n", (3*x+5*y-1)/5);
				return 0;
			}
		}
		if((2*x-1)%5==0) {
			i++;
			if(i==15) {
				printf("%lld\n", (2*x-1)/5);
				return 0;
			}
		}
		if((p+5*q-1)%5==0) {
			i++;
			if(i==15) {
				printf("%lld\n", (p+5*q-1)/5);
				return 0;
			}
		}
		a = x; b = y;
		x = 9*a+20*b;
		y = 4*a+9*b;
		a = p; b = q;
		p = 9*a+20*b;
		q = 4*a+9*b;
	}
	return 0;
}
