#include<stdio.h>
int perm[24];
int x[4];
int it;
void fillDigit(int n)
{
	int i,p;
	p = 1000;
	for(i=0;i<4;i++)
	{
		x[i] = n/p;
		n = n%p;
		p = p/10;
	}
	return;
}

void cleanPerm()
{
	int i;
	it = 0;
	for(i=0;i<24;i++)
		perm[i] = 0;
	return;
}

void fillPerm(int n)
{
	int i,temp,lul;
	lul = 0;
	for(i=0;i<4;i++)
	{
		if (x[i] != -1)
		{
			lul = 1;
			temp = x[i];
			x[i] = -1;
			fillPerm(10*n+temp);
			x[i] = temp;
		}
	}
	if(lul == 0) {
		perm[it] = n;
		it++;
	}
	return;
}
int main()
{
	int seive[10000];
	int i,j,n,x;
	for(i=2;i<10000;i++)
		seive[i] = 0;
	for(i=2;i<100;i++)
		if(seive[i] == 0)
			for(j=i*i;j<10000;j=j+i)
				seive[j] = 1;
	for(i=1000;i<10000;i++) {
		if (seive[i] == 0) {
			fillDigit(i);
			cleanPerm();
			fillPerm(0);
			if (i != 1487) {
				for(j=0;j<24;j++) {
					if (perm[j]>i && seive[perm[j]]==0) {
						n = perm[j]-i+perm[j];
						if (n<10000 && seive[n]==0) {
							for(x=0;x<24;x++)
								if(n==perm[x])
								{
									printf("%d%d%d\t%d\n", i, perm[j], n, perm[j]-i);
									return 0;
								}
						}
					}
				}
			}
		}
	}
	return 0;
}
