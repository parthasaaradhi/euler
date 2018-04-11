#include<stdio.h>
int main()
{
	int seive[1000*1000];
	long long i,j,cs,cp,cc,mc,mp;
	for(i=2;i<1000*1000;i++)
		seive[i] = 0;
	for(i=2;i<1000;i++)
		if(seive[i] == 0)
			for(j=i*i;j<1000*1000;j=j+i)
				seive[j] = 1;
	cs = 2;
	cp = 2;
	cc = 1;
	mp = 2;
	mc = 1;
	while(mc == 1)
	{
		i=2;j=3;
		while(cs < 1000*1000 && j < 1000*1000) {
			if(seive[j] == 0) {
				cs = cs + j;
				if (cs < 1000*1000) {
					cc++;
					if(seive[cs] == 0) {
						mc = cc;
						mp = cs;
					}
				}
			}
			j++;
		}
	}
	printf("%lld %lld\n", mc, mp);
	return 0;
}
