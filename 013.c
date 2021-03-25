#include<stdio.h>
#include "hdr/013_input.h"

int main()
{
	int i,j,x;
	int final_sum[54];
	for(i=0;i<54;i++)
		final_sum[i] = 0;
	int** a = input_digits_call(100, 50);
	x = 53;
	for(j=49;j>-1;j--)
	{
		for(i=0;i<100;i++)
		{
			final_sum[x]=final_sum[x] + a[i][j];
		}
		final_sum[x-1] = final_sum[x]/10;
		final_sum[x] = final_sum[x]%10;
		x--;
	}
	x = 0;
	for(i=53;i>-1;i--)
	{
		final_sum[i] = (x+final_sum[i])%10;
		x = final_sum[i]/10;
	}
	i=0;
	while(final_sum[i]==0)
		i++;
	for(j=i;j<i+10;j++)
		printf("%d", final_sum[j]);
	printf("\n");
	return 0;
}
