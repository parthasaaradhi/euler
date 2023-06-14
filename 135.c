#include<stdio.h>
#define million 1000000
int check(long long x, long long y) {
	long long b,d;
	if((x+y)%4 !=0) return 1;
	b=x;d=(x+y)/4;
	if(b<=d) return 1;
	return 0;
}
int main() {
	long long totals[million];
	long long i,j;
	for(i=0;i<million;i++) totals[i]=0;
	for(i=1;i<million;i++)
		for(j=1;j<(3*i) && (i*j)<million;j++)
			if(check(i,j) == 0)
				totals[i*j]++;
	j=0;
	for(i=0;i<million;i++)
		if(totals[i] == 10) j++;
	printf("%lld\n", j);
	return 0;
}
