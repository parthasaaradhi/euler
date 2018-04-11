#include<stdio.h>
#define N 30000
int main() {
	long long A[N];
	long long B[2*N];
	long long i,j,s;
	s=0;
	for(i=0;i<N;i++) {
		A[i] = 0;
		B[i] = 0;
		B[2*i] = 0;
	}
	for(i=1;i<N;i++)
		for(j=2*i;j<N;j=j+i)
			A[j] = A[j] + i;
	for(i=1;i<N;i++)
		if (A[i] > i) {
			for(j=1;j<N;j++)
				if (A[j] > j)
					B[i+j] = 1;
		}
	for(i=1;i<=28123;i++)
		if ( B[i] != 1)
			s = s + i;
	printf("%lld\n", s);
	return 0;
}
