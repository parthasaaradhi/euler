#include<stdio.h>

int maxPower(long long n, int p) {
	int s = 0;
	while(n%p == 0) {
		n = n/p;
		s++;
	}
	return s;
}

int main()
{
	int i,j;
	long long n = 0;
	long long s = 1;
	int seive[500];
	for(i=2;i<500;i++)
		seive[i] = 0;
	seive[0] = 1;
	seive[1] = 1;
	for(i=2;i<23;i++)
		if(seive[i] == 0)
			for(j=i*i;j<500;j = j+i)
				seive[j] = 1;
	j = 1;
	while(s < 500) {
		n = n + j;
		s = 1;
		for(i=2;i<500;i++) {
			if (seive[i] == 0) {
				s = s * (1+maxPower(n, i));
			}
		}
		//printf("%d\n", s);
		j++;
	}
	printf("%lld\n", n);
	return 0;
}
