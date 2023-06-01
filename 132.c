#include<stdio.h>
#define limit 1000000
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
int main() {
	int seive[limit];
	int i,j,cnt,sum;;
	cnt=0;sum=0;
	for(i=0;i<limit;i++) seive[i]=0;
	for(i=2;i<limit;i++)
		if(seive[i] == 0)
			for(j=2*i;j<limit;j=j+i)
				seive[j] = 1;
	for(i=7;cnt<40 && i<limit;i++)
		if(seive[i] == 0)
			if(target%count(i)==0) {
				//printf("%d\n", i);
				cnt++;
				sum = sum+i;
			}
	printf("%d\n", cnt);
	printf("Total sum:%d\n", sum);
	return 0;
}
