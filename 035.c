#include<stdio.h>
int main() {
	int seive[1000*1000];
	long long i,pow,n,perm,f,len;
	long long sum;
	for(i=0;i<1000*1000;i++)
		seive[i] = 0;
	for(i=2;i<1002;i++)
		for(f=i*i;f<1000*1000;f=f+i)
			seive[f] = 1;
	pow = 1;
	len = 1;
	sum = 0;
	for(i=2;i<1000*1000;i++) {
		if (i == 10 || i == 100 || i == 1000 || i == 1000*10 || i == 1000*100) {
			pow = pow * 10;
			len = len+1;
		}
		if (seive[i] == 0) {
			perm = i;
			f = 0;
			for(n=0;n<len;n++) {
				perm = (perm%10)*pow + perm/10;
				if (seive[perm] != 0)
					f = 1;
			}
			if(f == 0) {
				sum = sum + 1;
				//printf("%lld\n", i);
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}
