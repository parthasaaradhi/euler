#include<stdio.h>
long long sum;
int digits[10];
int lulz[11] = {1, 17, 13, 11, 7, 5, 3, 2, 1, 1, 1};
void perm(long long n, int d) {
	long long i,f,x;
	if(d == 0)
		sum = sum + n;
		//printf("%lld\n", n);
	else {
		for(i=0;i<10;i++)
			if(digits[i] == 0) {
				f = 0;
				x = i+10*(n%100);
				f = (x%lulz[d] != 0)? 1 : f;
				if (f == 0) {
					digits[i] = 1;
					perm(n*10+i, d-1);
					digits[i] = 0;
				}
			}
	}
}
int main()
{
	int i;
	sum = 0;
	for(i=0;i<10;i++)
		digits[i] = 0;
	perm(0,10);
	printf("%lld\n", sum);
	return 0;
}
