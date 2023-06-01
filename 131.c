#include<stdio.h>
#define limit 1000000
int is_perfect_square(int n) {
	int i;
	i=1;
	while(i*i<n) i++;
	return i*i==n? 0 : 1;
}
int main() {
	int seive[limit]; int i,j,cnt;
	cnt=0;
	for(i=0;i<limit;i++) seive[i]=0;
	for(i=2;i<limit;i++)
		if(seive[i] == 0)
			for(j=2*i;j<limit;j=j+i)
				seive[j] = 1;
	for(i=2;i<limit;i++)
		if(seive[i] == 0)
			if(((4*i-1)%3==0) && (is_perfect_square((4*i-1)/3) == 0)) {
				cnt++;
				//printf("%d\n", i);
			}
	printf("%d\n", cnt);
	return 0;
}
