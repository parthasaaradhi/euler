#include<stdio.h>
long long A[1000*1000];

long long chain(long long n) {
	if (n == 1)
		return 1;
	
	if (n < 1000*1000) {
		if (A[n] != -1)
			return A[n];
		else {
			A[n] = 1 + ((n%2 == 0)? chain(n/2) : chain(3*n+1));
			return A[n];
		}
	}
	else {
		return 1 + ((n%2 == 0)? chain(n/2) : chain(3*n+1));
	}
}

int main()
{
	long long i=0;
	long long temp;
	long long max=1;
	long long st = 2;
	for(i=0;i<1000*1000;i++)
		A[i] = -1;

	for(i=2;i<1000 * 1000;i++) {
		temp = chain(i);
		st = temp > max ? i : st;
		max = temp > max ? temp : max;
	}
	printf("%lld: %lld\n", st, max);
	return 0;
}
