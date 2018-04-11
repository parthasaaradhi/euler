#include<stdio.h>
int main() {
	int seive[2002000];
	long long a,b,i,j,p,m;
	long long A,B;
	m = 0;
	seive[1] = 1;
	seive[0] = 1;
	for(i=2;i<2002000;i++)
		seive[i] = 0;
	for(i=2;i<2002000;i++)
		if (seive[i] == 0)
			for(j=i*i;j<2002000;j=j+i)
				seive[j] = 1;
	for(i=2;i<1001;i++)
		if (seive[i] == 0) {
			b = i;
			for(a=-1*b-1;a<1000;a++) {
				j = 1;
				p = j*j+j*a+b;
				while(p > 0 && p < 2002000 && seive[p] == 0) {
					j++;
					p = j*j+j*a+b;
				}
				if(j>m) {
					m = j;
					A = a;
					B = b;
				}
			}
		}
	printf("%lld:%lld\n", A*B, m);
	return 0;
}
