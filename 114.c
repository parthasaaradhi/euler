#include<stdio.h>
/*
 * R(n-1) -> G
 * R(n-1) -> R
 * G(n-1) -> G
 * G(n-1) -> ggg givs grrr;
 * F(n) = R(n-1)*2 + G(n-1) + F(n-4);
 * G(n-1) = F(n-1) - F(n-2);
 * */
int main() {
	long long i,a,b,c,d,t;
	a=1;b=1;c=2;d=4;
	for(i=5;i<51;i++) {
		t = d;
		d = 2*d - c + a;
		a=b;b=c;c=t;
	}
	printf("%lld\n", d);
	return 0;
}
