#include<stdio.h>
long long mydiffsq(int n)
{
	return (n*(n*n-1)*(3*n+2))/12;
}
int main()
{
	printf("%lld, %lld\n", mydiffsq(10), mydiffsq(100));
	return 0;
}
