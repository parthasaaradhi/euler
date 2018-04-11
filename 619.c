#include<stdio.h>
int main()
{
	int seive[1234568];
	int primes[95360];
	char pmask[234568][95360];
	long long i,j,n;
	for(i=1;i<1234568;i++)
		seive[i] = 0;
	seive[1] = 1;
	for(i=2;i<1234;i++) {
		if(seive[i] == 0) {
			for(j=i*i;j<1234568;j=j+i)
				seive[j] = 1;
		//printf("%d ", i);
		}
	}
	j=0;
	for(i=2;i<1234568;i++) {
		if(seive[i] == 0) {
			printf("%lld : %lld\n", j, i);
			primes[j] = i;
			j++;
		}
	}
	for(i=0;i<234568;i++) {
		for(j=0;j<95360;j++) {
			pmask[i][j] = '0';
		}
	}/*
	for(i=2;i<1234568;i++) {
		n = i;
		for(j=0;j<95360;j++) {
			while(n%primes[j] == 0) {
				n = n / primes[j];
				pmask[i][j] = (pmask[i][j] == '0') ? '1' : '0';
			}
		}
	}*/
	return 0;
}
