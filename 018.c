#include<stdio.h>
int main()
{
	int N = 15*8;
	long long A[15*8 + 1];
	int i,l;
	for(i=1;i<=N;i++)
		scanf("%lld", &A[i]);
	for(l=14;l>0;l--) {
		for(i=1;i<=l;i++)
			A[(l*(l-1))/2 + i] = A[(l*(l-1))/2 + i] + (A[(l*(l+1))/2 + i] > A[(l*(l+1))/2 + i + 1] ? A[(l*(l+1))/2 + i] : A[(l*(l+1))/2 + i + 1]);
	}
	printf("%lld\n", A[1]);
	return 0;
}
