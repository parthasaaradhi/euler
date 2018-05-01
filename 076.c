#include<stdio.h>
long long dp[101][101];
long long f(int x, int y) {
	long long z,q,i;
	if(y == 1)
		return 1;
	if(dp[x][y] != -1)
		return dp[x][y];
	z = 0;
	q = x/y;
	for(i=0;i<=q;i++)
		z = z + f(x-i*y, y-1);
	dp[x][y] = z;
	return z;
}
int main()
{
	int i,j;
	for(i=0;i<101;i++)
		for(j=0;j<101;j++)
			dp[i][j] = -1;
	printf("%lld\n", f(100, 99));
	return 0;
}
