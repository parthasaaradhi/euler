#include<stdio.h>
int main()
{
	long long fac[10];
	long long n,i,s,sum;
	fac[0] = 1;
	for(i=1;i<10;i++)
		fac[i] = fac[i-1] * i;
	n = 3;
	sum=0;
	while(n<2177280) {
		s = 0;
		i = n;
		while(i!=0) {
			s = s + fac[i%10];
			i = i / 10;
		}
		if(s == n)
			sum = sum + n;
			//printf("%d\n", n);
		n++;

	}
	printf("%lld\n", sum);
	return 0;
}
