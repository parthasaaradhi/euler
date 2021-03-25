#include<stdio.h>
int sum_of_divisors(int n, int sq)
{
	int i;int s;
	s=1;
	for(i=2;i<sq;i++)
		if(n%i==0)
			s = s + i + n/i;
	if(n==sq*sq)
		s=s+sq;
	return s;
}

int main()
{
	int a[10000+1];
	int n,sq;
	sq=1;
	a[0]=0;
	a[1]=1;
	for(n=2;n<10000+1;n++)
	{
		if(n == (sq+1)*(sq+1))
			sq++;
		a[n] = sum_of_divisors(n, sq);
	}
	sq=0;
	for(n=2;n<10000+1;n++)
		if(a[n]<10000+1 && n!=a[n] && a[a[n]] == n)
			sq+=n;
	printf("%d\n", sq);
	return 0;
}
