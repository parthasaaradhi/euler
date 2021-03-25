#include<stdio.h>

long long minimum(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	long long a[80][80];
	long long i,j;
	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	/*
	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
			printf("%lld ", a[i][j]);
		printf("\n");
	}
	*/
	for(i=78;i>=0;i--)
	{
		a[79][i] = a[79][i] + a[79][i+1];
		a[i][79] = a[i][79] + a[i+1][79];
	}
	
	for(i=78;i>=0;i--)
	{
		for(j=78;j>=0;j--)
		{
			a[i][j] = a[i][j] + minimum(a[i][j+1], a[i+1][j]);
		}
	}
	/*
	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
			printf("%lld ", a[i][j]);
		printf("\n");
	}
	*/
	printf("%lld\n", a[0][0]);
	return 0;
}
