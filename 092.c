#include<stdio.h>

#define N 10*1000*1000

long long recur(long long n)
{
	//printf("Recur : %lld\n", n);
	if(n == 89 || n == 1)
		return n;

	long long s = 0;
	long long x = n;
	while(x!=0)
	{
		s = s + (x%10)*(x%10);
		x=x/10;
	}
	if(s==n)
		return 0;
	else
		return recur(s);
}
int main()
{
	long long k,t,s;
	s=0;
	for(k=1;k<N;k++)
	{
		t=recur(k);
		if(t==89)
		{
			//printf("%lld : %lld\n",k, t);
			s++;
		}
	}
	printf("Final Count:%lld\n", s);
	return 0;
}
