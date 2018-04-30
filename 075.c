#include<stdio.h>

long long gcd(long long m, long long n) {
	if(n == 0)
		return m;
	return gcd(n, m%n);
}

int main()
{
	int totals[1000*100*15+1];
	long long i,j;
	for(i=1;i<1000*100*15+1;i++) {
		totals[i] = 0;
	}
	long long m,n;
	n = 1;
	while(n<867) {
		m = n + 1;
		while((m*(m+n)) <= 750000) {
			if(gcd(m,n) == 1) {
				//printf("%lld : %lld\n", m, n);
				j = 1;
				while((j*m*(m+n)) <= 750000) {
					totals[2*j*m*m + 2*j*m*n]++;
					//printf("%lld : %lld : %lld\n", j*(m*m - n*n), 2*m*n*j, j*(m*m + n*n));
					j++;
				}
			}
			m = m + 2;
		}
		n++;
	}
	j=0;
	for(i=1;i<1000*100*15+1;i++)
		if(totals[i] == 1)
			j++;
	printf("%lld\n", j);
	return 0;
}
