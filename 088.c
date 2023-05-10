#include<stdio.h>

int dp[100][100][100];

int is_possible(int pr, int sm, int k) {
	if(sm<0 || k<0) return 1;
	if(pr<100 && sm<100 && k<100 && dp[pr][sm][k]!=-1)
		return dp[pr][sm][k];
	if(pr==1 && sm==k) return 0;
	if(pr==1 && sm!=k) return 1;
	if(sm<k) return 1;
	int i;
	for(i=pr;i>1;i--) {
		if(pr%i == 0)
			if(is_possible(pr/i, sm-i, k-1) == 0) {
				//printf("%d ",i);
				if(pr<100 && sm<100 && k<100)
					dp[pr][sm][k] = 0;
				return 0;
			}
	}
	if(pr<100 && sm<100 && k<100)
		dp[pr][sm][k] = 1;
	return 1;
}

int main() {
	int i,j,k,ans;
	int N[15000];
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			for(k=0;k<100;k++)
				dp[i][j][k] = -1;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			dp[1][i][j] = 1;
	for(i=0;i<100;i++)
		dp[1][i][i] = 0;

	ans = 0;
	for(i=0;i<15000;i++) N[i] = 0;
	for(i=2;i<=12000;i++) {
		k=1; j=i-1;
		while(k!=0) {
			j++;
			k = is_possible(j,j,i);
		}
		N[j] = 1;
		//printf("%d %d\n", i, j);
	}
	for(j=0;j<15000;j++) ans = ans + N[j]*j;
	printf("%d\n", ans);
	return 0;
}
