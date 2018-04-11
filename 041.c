#include<stdio.h>
int main()
{
	char seive[5000];
	int digits[10];
	long long i,j,n,f;
	seive[0] = '1'; seive[1] = '1';
	for(i=2;i<5000;i++)
		seive[i] = '0';
	for(i=2;i<80;i++)
		if (seive[i] == '0') {
			for(j=i*i;j<5000;j=j+i)
				seive[j] = '1';
		}
	n = 7654321;
	while(n > 7123455) {
		f = 0;
		for(i=2;i<5000;i++) {
			if(seive[i] == '0') {
				if (n%i == 0) {
					f = 1;
					break;
				}
			}
		}
		if (f == 0) {
			for(i=0;i<10;i++)
				digits[i] = 0;
			i = n;
			while(i!=0) {
				digits[i%10]++;
				i = i/10;
			}
			for(i=1;i<8;i++)
				if (digits[i] != 1)
					f = 1;
			if (f == 0) {
				printf("%lld\n", n);
				return 0;
			}
		}
		n--;
	}
	//printf("%lld\n", j);
	return 0;
}
