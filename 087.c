#include<stdio.h>
#define N 50*1000*1000

int primes[8000];
int lol[N];

int main()
{
	long long i,j,t;
	long long x,y,z;
	for(i=0;i<50*1000*1000;i++)
		lol[i]=0;
	for(i=0;i<8000;i++)
	{
		primes[i] = 0;
	}
	for(i=2;i<8000;i++)
	{
		if(primes[i]==0)
		{

			for(j=i*2;j<8000;j=j+i)
			{
				primes[j] = 1;
			}
		}
	}
	for(i=2;i<8000;i++)
	{
		if(primes[i]==0) {
			x=i*i*i*i;
			if(x<N)
			{
				for(j=2;j<8000;j++)
				{
					if(primes[j]==0)
					{
						y=j*j*j;
						if(x+y<N)
						{
							for(t=2;t<8000;t++)
							{
								if(primes[t]==0)
								{
									z=t*t;
									if(x+y+z<N)
										lol[x+y+z] = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	z=0;
	for(i=2;i<N;i++)
		if(lol[i]==1)
		{
			z++;
			//printf("%lld\n", i);
		}
	printf("Final : %lld\n", z);
	return 0;
}
