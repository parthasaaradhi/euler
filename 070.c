#include<stdio.h>
int is_permutation(long long m, long long n) {
	int m_d[10],i;
	for(i=0;i<10;i++)
		m_d[i] = 0;
	while(m!=0) {
		m_d[m%10]++;
		m=m/10;
	}
	while(n!=0) {
		m_d[n%10]--;
		n=n/10;
	}
	for(i=0;i<10;i++)
		if(m_d[i] !=0)
			return 1;
	return 0;
}

int main() {
	char primes[1000000];
	long long i,j;
	float lx,cx;
	long long m;
	lx = 10.0;
	m = 2;
	for(i=0;i<1000*1000;i++)
		primes[i] = '0';
	for(i=2;i<1000;i++)
		if(primes[i] == '0')
			for(j=i*i;j<1000*1000;j=j+i)
				primes[j] = '1';
	for(j=1000*10;j>1;j--) {
		if(primes[j] == '0') {
			for(i=j-1;i>1;i--) {
				if(primes[i] == '0') {
					if(i*j <= (1000*10000)) {
						if(is_permutation(i*j, (i-1)*(j-1)) == 0) {
							cx = ((double) (i*j) / ((double) ((i-1)*(j-1))));
							m = lx > cx ? i*j : m;
							lx = lx > cx ? cx : lx;
							printf("%lld : %lld : %f\n", i*j, (i-1)*(j-1), cx);
						}
					}
				}
			}
		}
	}
	printf("Ans : %lld : %f\n", m, lx);
	return 0;
}
