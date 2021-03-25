#include<stdio.h>
int lcm(int* p,int n)
{
	int lcm = 1;
	int i,j;
	for(i=0;i<n;i++)
	{
		lcm = lcm * p[i];
		for(j=i+1;j<n;j++)
		{
			if(p[j]%p[i]==0)
				p[j]=p[j]/p[i];
		}
	}
	return lcm;
}
int main()
{
	int a[20],i;
	for(i=0;i<20;i++)
		a[i]=i+1;
	printf("%d\n", lcm(a, 20));
}
