#include<stdio.h>
#define limit 2000000000000
int main() {
	long long l,k,n,x,ln,kn;
	l=1;k=1;
	while(l<limit) {
		kn=k;ln=l;
		l = 3*ln+4*kn;
		k = 2*ln+3*kn;
	}
	printf("%lld\n", (1+l)/2);
	printf("%lld\n", (1+k)/2);
	return 0;
}
