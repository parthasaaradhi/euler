#include<stdio.h>
int primes[1000];
int f(int x, int y)
{
	int q,z,i,np;
	if(y == 2)
		if(x%2 == 0)
			return 1;
		else
			return 0;
	q = x/y;
	z = 0;
	i=y-1;
	while(primes[i] == 1)
		i--;
	np = i;
	for(i=0;i<=q;i++)
	{
		z = z + f(x-i*y, np);
	}
	return z;
}

int main()
{
	int i,j;
	for(i=0;i<1000;i++)
		primes[i] = 0;
	for(i=2;i<100;i++)
		if(primes[i] == 0)
			for(j=i*i;j<1000;j=j+i)
				primes[j] = 1;
	for(i=2;i<1000;i++) {
		if(primes[i] == 0)
			j = i;
		if(f(i, j)> 5000)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
