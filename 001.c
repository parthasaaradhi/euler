#include<stdio.h>
#define sum(n) (n*(n+1))/2
int main()
{
	int N=999;
	printf("%d\n", 3*sum(N/3) + 5*sum(N/5) - 15*sum(N/15));
	return 0;
}       
