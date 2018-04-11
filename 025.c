#include<stdio.h>
int main()
{
	int A[1000];
	int B[1000];
	int C[1000];
	int i,c;
	long long n;
	for(i=999;i>0;i--)
	{
		A[i] = 0;
		B[i] = 0;
		C[i] = 0;
	}
	A[0] = 1;
	B[0] = 1;
	C[0] = 0;
	n = 2;
	while(A[999] == 0) {
		c = 0;
		for(i=0;i<1000;i++)
			C[i] = A[i];
		for(i=0;i<1000;i++) {
			A[i] = A[i] + B[i] + c;
			c = A[i]/10;
			A[i] = A[i]%10;
		}
		for(i=0;i<1000;i++)
			B[i] = C[i];
		n++;
	}
	printf("%lld\n", n);
	return 0;
}
