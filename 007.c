#include<stdio.h>
int main()
{
	int sqrt_now = 1;
	int n=2;
	int i,j;
	int count_primes=0;
	while(count_primes!=10000+1)
	{
		j=0;
		if(n == (sqrt_now+1)*(sqrt_now+1))
		{
			sqrt_now++;
			j=1;
		}
		for(i=2;i<=sqrt_now&&j==0;i++)
		{
			if(n%i==0)
				j=1;
		}
		if(j==0)
			count_primes++;
		n++;
	}
	printf("%d\n", n-1);
	return 0;
}
