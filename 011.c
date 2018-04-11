#include<stdio.h>
int main()
{
	long long prod = 0;
	long long s = 1;
	long long A[26][26];
	int i,j;
	for(i=0;i<26;i++)
		for(j=0;j<26;j++)
			A[i][j] = 0;
	
	for(i=3;i<23;i++) {
		for(j=3;j<23;j++) {
			scanf("%lld", &A[i][j]);
		}
	}
	for(i=3;i<23;i++) {
		for(j=3;j<23;j++) {
			s = A[i][j] * A[i][j+1] * A[i][j+2] * A[i][j+3];
			prod = s > prod ? s: prod;
			s = A[i][j] * A[i+1][j] * A[i+2][j] * A[i+3][j];
			prod = s > prod ? s: prod;
			s = A[i][j] * A[i+1][j+1] * A[i+2][j+2] * A[i+3][i+3];
			prod = s > prod ? s: prod;
			s = A[i][j] * A[i+1][j-1] * A[i+2][j-2] * A[i+3][j-3];
			prod = s > prod ? s: prod;
		}
	}
	printf("%lld\n", prod);
	return 0;
}
