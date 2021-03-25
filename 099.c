#include<stdio.h>
int main()
{
	long long base_exp[1000][2];
	int i;
	for(i=0;i<1000;i++)
	{
		scanf("%lld", &base_exp[i][0]);
		scanf("%lld", &base_exp[i][1]);
	}
	return 0;
}
