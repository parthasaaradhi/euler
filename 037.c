#include<stdio.h>
int main()
{
	int seive[1000*1000];seive[0] = 1;seive[1] = 1;
	int i,m,bul,n,pow;
	long long sum=0;
	for(i=2;i<1000*1000;i++)
		seive[i] = 0;
	for(i=2;i<1002;i++)
		if (seive[i] == 0)
			for(n=i*i;n<1000*1000;n=n+i)
				seive[n] = 1;
	
	for(i=10;i<1000*1000;i++) {
		if (seive[i] == 0) {
			m = i;
			bul = 0;
			pow = 1;
			while(m>9) {
				m = m/10;
				if (seive[m] != 0)
					bul = 1;
			}
			m = i;
			n = 0;
			while(m != 0) {
				n = n + (m%10)*pow;
				pow = pow * 10;
				m = m/10;
				if (seive[n] != 0)
					bul = 1;
			}
		if(bul == 0)
			sum = sum + i;
			//printf("%d\n", i);
		}
	}
	printf("%lld\n", sum);
	return 0;
}
