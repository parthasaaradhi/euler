#include<stdio.h>
void initalize(long long* seive) {
	long long i,j;
	for(i=0;i<1000000;i++) seive[i]=0;
	for(i=2;i<1000;i++)
		if(seive[i] == 0)
			for(j=2*i;j<1000000;j=j+i) seive[j] = 1;
	return;
}

long long find(long long x, long long y) {
	long long p,t;
	t=x;p=1;
	while(t!=0) {
		t=t/10;
		p=10*p;
	}
	t=1;
	while((p*t+x)%y!=0) t++;
	return p*t+x;
}

int main() {
	long long seive[1000000];
	long long x,y,i,sum;
	initalize(seive);
	x = 3; y = 5; sum=0;
	for(i=6;i<1000*1000;i++)
		if(seive[i] == 0)
		{
			x=y;
			y=i;
			sum = sum + find(x,y);
			//printf("%lld\n", find(x,y));
		}
	sum = sum + find(y, 1000003);
	printf("%lld\n",sum);
	return 0;
}
