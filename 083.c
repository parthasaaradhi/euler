#include<stdio.h>
#define N 80
long long a[N][N][2];

long long minimum(long long a, long long b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	return a < b ? a : b;
}

long long fn(int i, int j)
{
	long long local = a[i][j][1];
	if(i==N-1 && j==N-1)
		return local;
	long long x,y,z,w;
	x=y=z=w=0;
	//Left
	if(j-1>=0)
	{
		if(a[i][j-1][0] != 1)
		{
			a[i][j-1][0] = 1;
			x = fn(i,j-1);
			a[i][j-1][0] = 0;
		}
	}
	//Right
	if(j+1<N)
	{
		if(a[i][j+1][0] != 1)
		{
			a[i][j+1][0] = 1;
			y = fn(i,j+1);
			a[i][j+1][0] = 0;
		}
	}
	//Up
	if(i-1>=0)
	{
		if(a[i-1][j][0] != 1)
		{
			a[i-1][j][0] = 1;
			z = fn(i-1,j);
			a[i-1][j][0] = 0;
		}
	}
	//Down
	if(i+1<N)
	{
		if(a[i+1][j][0] != 1)
		{
			a[i+1][j][0] = 1;
			w = fn(i+1,j);
			a[i+1][j][0] = 0;
		}
	}

	x = minimum(minimum(x,y), minimum(z,w));
	if(x == 0)
		return 0;
	else
		return local+x;
}
int main()
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			scanf("%lld", &a[i][j][1]);
			a[i][j][0] = 0;
		}
	a[0][0][0] = 1;
	printf("%lld\n", fn(0,0));
	return 0;
}
