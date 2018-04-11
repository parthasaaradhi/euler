#include<stdio.h>
int main()
{
	int A[200];
	int i,j,carry;
	for(i=0;i<200;i++)
		A[i] = 0;
	A[0] = 1;
	for(j=2;j<100;j++) {
		carry = 0;
		for(i=0;i<200;i++) {
			A[i] = A[i] * j + carry;
			carry = A[i]/10;
			A[i] = A[i]%10;
		}
	}
	carry = 0;
	for(i=0;i<200;i++)
		carry = carry + A[i];
	printf("%d\n", carry);
	return 0;
}
