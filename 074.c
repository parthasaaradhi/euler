#include<stdio.h>
long long fac[10];
long long chain[1000*1000];
long long minor_chains[7] = {169, 363601, 1454, 871, 45361, 872, 45362};
long long minor_chain_len[7] = {3, 3, 3, 2, 2, 2, 2};

long long fac_sum(long long n)
{
	long long x = 0;
	while(n!=0) {
		x = x + fac[n%10];
		n = n/10;
	}
	return x;
}

int main()
{
	long long n,x,s,i,f,lulz;
	long long chain[1000*1000];
	fac[0] = 1;
	for(n=1;n<10;n++)
		fac[n] = fac[n-1] * n;
	chain[0] = 1;
	for(n=1;n<1000*1000;n++)
		chain[n] = fac_sum(n);
	n = 69;
	lulz = 0;
	while(n<1000*1000)
	{
		x = 0;
		s = n;
		f = 0;
		while(f!= 1)
		{
			//printf("%lld :", s);
			for(i=0;i<9;i++)
			{
				if(s == minor_chains[i])
				{
					f = 1;
					x = x + minor_chain_len[i];
				}
			}
			if(f != 1)
			{
				if(s>=1000*1000) {
					if(s == fac_sum(s)) {
						f = 1;
					} else {
						s = fac_sum(s);
					}
				} else {
					if(s == chain[s]) {
						f = 1;
					} else {
						s = chain[s];
					}
				}
				x++;
			}
		}
		n++;
		//printf("Total = %lld\n", x);
		if(x == 60)
			lulz++;
	}
	printf("Final Answer:%lld\n", lulz);
	return 0;
}
