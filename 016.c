#include<stdio.h>
int main()
{
	int A[500];
	int carry = 0;
	long long sum = 0;
	int i,j;
	for(i=0;i<500;i++)
		A[i]=0;
	A[0] = 1;
	for(i=1;i<=1000;i++) {
		carry = 0;
		for(j=0;j<500;j++) {
			A[j] = A[j] * 2 + carry;
			carry = A[j]/10;
			A[j] = A[j]%10;
		}
	}
	for(i=0;i<500;i++)
		sum = sum + A[i];
	printf("%lld\n", sum);
	return 0;
}
