#include<stdio.h>
#define million 50000000
int check(long long x, long long y) {
	long long b,d;
	if((x+y)%4 !=0) return 0;
	b=x;d=(x+y)/4;
	if(b<=d) return 0;
	return 1;
}
int factorize(long long n) {
	long long x,y;
	int ans;
	ans = 0;
	for(x=1;x*x<n;x++)
		if(n%x==0) {
			y = n/x;
			if((x+y)%4==0) {
				if (x>((x+y)/4)) ans++;
				if (y>((x+y)/4)) ans++;
			}
			if(ans>1) return 0;
		}
	if(x*x == n) ans = ans + check(x,x);
	return ans;
}

int main() {
	long long n,ans;
	n=1;ans=0;
	while(n<million) {
		if(factorize(n) == 1) ans ++;
		n++;
	}
	printf("%lld\n", ans);
	return 0;
}
