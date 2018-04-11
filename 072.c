#include<stdio.h>
int main()
{
	char primes[1000*1000];
	int totient[1000*1000];
	long long i,j,s;
	s = 0; // PHI(1) = 1; 1 + Sigma - 2 {0/N, 1/1}
	for(i=0;i<1000*1000;i++) {
		primes[i] = '0';
		totient[i] = i;
	}
	for(i=2;i<1000;i++ ) {
		if(primes[i] == '0') {
			for(j=i*i;j<1000*1000;j=j+i)
				primes[j] = '1';
		}
	}
	for(i=2;i<1000*1000;i++) {
		if(primes[i] == '0') {
			for(j=i;j<1000*1000;j=j+i) {
				totient[j] = (totient[j]/i) * (i-1);
			}
		}
	}
	for(i=2;i<1000*1000;i++) {
		s = s + totient[i];
	}
	s = s + 1000*100*4; // (N * 0.5 * 0.8)
	printf("%lld\n", s);
	return 0;
}
