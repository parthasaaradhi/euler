#include<stdio.h>
int main() {
	int primes[1000000];
	int totient[1000000];
	int i,j;
	float lx,cx;
	for(i=0;i<1000*1000;i++)
		primes[i] = 0;
	for(i=2;i<1000;i++)
		if(primes[i] == 0)
			for(j=i*i;j<1000*1000;j=j+i)
				primes[j] = 1;
	for(i=0;i<1000*1000;i++)
		totient[i] = i;
	for(i=2;i<1000*1000;i++) {
		if(primes[i] == 0) {
			for(j=i;j<1000*1000;j=j+i) {
				totient[j] = (totient[j]/i) * (i-1);
			}
		}
	}
	lx = 0.0;
	j = 0;
	for(i=2;i<1000*1000;i++) {
		cx = ((double) i) / ((double) totient[i]);
		//printf("%lld : %lld : %f\n", i, totient[i], cx);
		j = cx > lx ? i : j;
		lx = cx > lx ? cx : lx;
	}
	printf("Answer: %d: %f\n", j, lx);
	return 0;
}
