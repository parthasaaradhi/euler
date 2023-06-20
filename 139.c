#include<stdio.h>
#define hm 100000000

long long gcd(long long a, long long b) {
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b, a%b);
}
long long absol(long long a, long long b) {
	return a>b? (a-b) : (b-a);
}

int main() {
	long long m,n,a,b,c,k,ans;
	n=1;ans=0;
	while(n<5000) {
		m=n+1;
		while(2*m*m+2*m*n < hm) {
			if(gcd(m,n) == 1) {
				a = m*m-n*n;
				b = 2*m*n;
				c = m*m+n*n;
				if(c%absol(a,b)==0) {
					k = hm/(a+b+c);
					ans = ans + k;
					//for(k=1;k<hm/(a+b+c);k++)
					//printf("%lld %lld %lld\n", a, b, c);
				}
			}
			m=m+2;
		}
		n++;
	}
	printf("%lld\n", ans);
	return 0;
}
