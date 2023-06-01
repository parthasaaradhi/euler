#include<stdio.h>
#define limit 100000
#define target 1000000000
int count(int n) {
	int r,cnt;
	cnt=1;r=1%n;
	while(r!=0) {
		r = 10*r+1;
		r = r%n;
		cnt++;
	}
	return cnt;
}
int only_two_and_five(int n) {
	while(n%2==0) n=n/2;
	while(n%5==0) n=n/5;
	return n==1? 0 : 1;
}
int main() {
	int seive[limit];
	int i,j,sum;;
	sum=0;
	for(i=0;i<limit;i++) seive[i]=0;
	for(i=2;i<317;i++)
		if(seive[i] == 0)
			for(j=2*i;j<limit;j=j+i)
				seive[j] = 1;
	for(i=7;i<100000;i++)
		if(seive[i] == 0)
			if(only_two_and_five(count(i))!=0) {
				//printf("%d\n", i);
				sum = sum+i;
			}
	sum = sum + 2 + 3 + 5;
	printf("Total sum:%d\n", sum);
	return 0;
}
