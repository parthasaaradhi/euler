#include<stdio.h>
int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
long long d[200][8];
long long ways(int n, int x) {
	long long s,i,sum;
	if (d[n][x] != -1) {
		return d[n][x];
	} else {
		sum = 0;
		s = n - coins[x];
		while(s>0) {
			for(i=x-1;i>=0;i--)
				sum = sum + ways(s, i);
			s = s - coins[x];
		}
		if (s == 0)
			sum = sum + 1;
		d[n][x] = sum;
		return d[n][x];
	}

}
int main()
{
	long long s=0;
	int n = 200;
	int i,j;
	for(i=0;i<201;i++) {
		for(j=0;j<8;j++)
			d[i][j] = -1;
	}
	for(i=1;i<201;i++)
		d[i][0] = 1;
	for(i=7;i>-1;i--)
		 s = s + ways(200,i);
	printf("%lld\n", s);
	return 0;
}
