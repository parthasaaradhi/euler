#include<stdio.h>
int main() {
	long long principal[3][2] = {{7,1},{8,2},{13,5}};
	long long signs[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
	long long i,j,cnt,x,y,a,b,A,N,ans;
	x=9;y=4;cnt=0;ans=0;
	while(cnt<30) {
		for(i=0;i<3;i++) {
			for(j=0;j<4;j++) {
				A = signs[j][0]*principal[i][0]*x+signs[j][1]*5*principal[i][1]*y;
				N = signs[j][0]*principal[i][0]*y+signs[j][1]*principal[i][1]*x;
				if(N>0 && A>7 && (A-7)%5==0) {
					cnt++;
					//printf("%lld\n", (A-7)/5);
					ans = ans + (A-7)/5;
				}
			}
		}
		a=x;b=y;
		x=9*a+20*b;
		y=4*a+9*b;
	}
	printf("%lld\n", ans);
	return 0;
}
