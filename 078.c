#include<stdio.h>
int f(int n, int k)
{
	if(n == 0)
		return 1;
	if(k == 1)
		return 1;
	int s;
	s=0;
	while(n>=0)
	{
		s = s + f(n, k-1);
		n=n-k;
	}
	return s;
}
int main()
{
	printf("%d\n", f(55374,55374));
	return 0;
}
