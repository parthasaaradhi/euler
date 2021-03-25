#include<stdio.h>
#define N 80
long long minimum(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	long long a[N][N];
	long long temp[N];
	int i,j,x;
	long long local, b;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%lld", &a[i][j]);
	for(i=0;i<N;i++)
		temp[i]=0;

	for(j=N-2;j>=0;j--)
	{
		for(i=0;i<N;i++)
		{
			b = a[i][j];
			local = b + a[i][j+1];
			for(x=i-1;x>=0 && x!=i;x--)
			{
				local = minimum(b+a[x][j]+a[x][j+1], local);
				b=b+a[x][j];
			}

			b=a[i][j];
			for(x=i+1;x<N;x++)
			{
				local = minimum(b+a[x][j]+a[x][j+1], local);
				b=b+a[x][j];
			}
			temp[i]=local;
		}
		for(i=0;i<N;i++)
		{
			a[i][j] = temp[i];
		}
	}
	local = a[0][0];
	for(i=0;i<N;i++)
		local = minimum(local, a[i][0]);
	printf("%lld\n", local);
	return 0;
}
