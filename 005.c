#include<stdio.h>
int main()
{
	long long A[21];
	long long x,y;
	long long ans = 1;
	for(x = 0; x < 21 ; x++) {
		A[x] = x;
	}
	for(x = 2; x < 21; x++) {
		ans = ans * A[x];
		for(y = x + 1; y < 21; y++) {
			if (A[y] % A[x] == 0) {
				A[y] = A[y] / A[x];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
