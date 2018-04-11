#include<stdio.h>
int main()
{
	long long pow,n,x,i,j,s;
	long long pp[8] = {0, 9, 90, 900, 9000, 90000, 900000, 9000000};
	pow = 0;
	n = 1;
	while(pow<7) {
		s = 0;
		x = n;
		i = 0;
		while(x>(pp[i]*i)) {
			x = x - pp[i]*i;
			i++;
		}
		//printf("%lld : %lld : %lld\n", n, pp[i-1], x);
		for(j=0;j<i;j++) {
			s = s + pp[j];
		}
		printf("%lld : %lld\n", s+x/i, x%i);
		n = n * 10;
		pow++;
	}
	return 0;
}
