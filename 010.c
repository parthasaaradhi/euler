#include<stdio.h>
int is_prime(int i, int sqrt_now)
{
	int j;
	for(j=2;j<=sqrt_now;j++)
		if(i%j==0)
			return 1;
	return 0;
}
int main()
{
	long long s = 0;
	int i;
	int sqrt_now  = 1;
	for(i=2;i<2*1000*1000;i++)
	{
		if(i == (sqrt_now+1)*(sqrt_now+1))
			sqrt_now++;
		else
			s = s + (1-is_prime(i, sqrt_now))*i;
	}
	printf("%lld\n", s);
	return 0;
}
