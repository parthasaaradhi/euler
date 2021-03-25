#include<stdio.h>
#include "hdr/015_long_divison.h"

int main()
{
	int i,x,t;
	int a[200];
	for(i=0;i<200;i++)
		a[i]=0;
	a[199]=1;
	for(x=21;x<41;x++)
	{
		t=0;
		for(i=199;i>-1;i--)
			{
				a[i] = t + a[i]*x;
				t = a[i]/10;
				a[i] = a[i]%10;
			}

	}
	i=0;
	while(a[i]==0)
		i++;
	while(i<200)
	{
		printf("%d",a[i]);
		i++;
	}
	printf("\n");
	long_divison_call(a, 20, 200);
	printf("\n");
	return 0;
}
