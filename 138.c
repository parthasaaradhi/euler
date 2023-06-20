#include<stdio.h>
int main() {
	long long x,y,a,b,i,h,l,ans;
	x=2;y=1;i=0;ans=0;
	while(i<12) {
		a=x;b=y;
		x=9*a+20*b;
		y=4*a+9*b;
		h=2*x+1;l=y;
		if(h%5==0) {
			//printf("%lld %lld %lld\n", h/5,h/5+1,l);
			i++;
			ans = ans+l;
		}
		h=2*x-1;
		if(h%5==0) {
			//printf("%lld %lld %lld\n", h/5,h/5-1,l);
			i++;
			ans = ans+l;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
