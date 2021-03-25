#include<stdio.h>
#define sigma_n2(n) n*(n+1)*(2*n+1)/6
#define sigma_n(n) n*(n+1)/2
int main()
{
	printf("%d\n", sigma_n(100)*sigma_n(100) - sigma_n2(100));
	return 0;
}
