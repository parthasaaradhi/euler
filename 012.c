#include<stdio.h>
int no_divisors(int n, int sq)
{
	int i;int s;
	s=0;
	for(i=1;i<sq;i++)
		if(n%i==0)
			s = s + 2;
	if (n == sq*sq)
		s++;
	return s;
}
int main()
{
	int i,k,sqrt_now;
	k = 0;
	i = 1;
	sqrt_now = 1;
	while(k<=500)
	{
		if((i*(i+1)/2) >= (sqrt_now+1)*(sqrt_now+1))
			sqrt_now++;
		k = no_divisors(i*(i+1)/2, sqrt_now);
		i++;
	}
	printf("%d\n", i*(i-1)/2);
	return 0;
}
