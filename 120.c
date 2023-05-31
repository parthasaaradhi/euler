#include<stdio.h>
int main() {
	long long n,a,max,sum,temp;
	sum=0;
	for(a=3;a<=1000;a++) {
		max=0;
		for(n=1;n<2*a;n=n+2) {
			temp = 2*n*a;
			temp = temp%(a*a);
			max = max > temp ?  max : temp;
		}
		sum = sum + max;
	}
	printf("%lld\n", sum);
	return 0;
}
