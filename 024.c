#include<stdio.h>
int main()
{
	long long A[10];
	long long n,i;
	A[0] = 1;
	for(i=1;i<10;i++) {
		A[i] = A[i-1] * i;
		printf("%lld ", A[i]);
	}
	printf("\n");
	n = 1000 * 1000 - 1;
	i = 9;
	while(n != 0) {
		printf("%lld ", n/A[i]);
		n = n%A[i];
		i--;
	}
	printf("\n");
	return 0;
}
