#include<stdio.h>
int main()
{
	int A[54];
	char B[50] = {'0'};
	int i=0;int j;
	for(i=0;i<54;i++) {
		A[i] = 0;
	}
	int carry;
	for(i=0;i<100;i++) {
		carry = 0;
		scanf("%s", B);
		for(j=49;j>=0;j--) {
			A[j+4] = A[j+4] + B[j] - 48 + carry;
			carry = A[j+4]/10;
			A[j+4] = A[j+4]%10;
		}
		for(j=3;j>=0;j--) {
			A[j] = A[j] + carry;
			carry = A[j]/10;
			A[j] = A[j]%10;
		}
	}
	i=0;j=0;
	while(A[i] == 0)
		i++;
	while(j<10) {
		printf("%d", A[i]);
		i++;j++;
	}
	printf("\n");
	return 0;
}
