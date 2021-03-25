#include<stdio.h>
int main()
{
	int digits[12];
	int i,j,x;
	for(i=0;i<12;i++)
		digits[i]=0;
	digits[0] = 1;
	for(i=1;i<=7830457;i++)
	{
		x = 0;
		for(j=0;j<12;j++)
		{
			digits[j] = digits[j]*2+x;
			x = digits[j]/10;
			digits[j] = digits[j]%10;
		}
	}
	x=0;
	for(i=0;i<12;i++)
	{
		digits[i] = 28433*digits[i]+x;
		x = digits[i]/10;
		digits[i] = digits[i]%10;
	}
	x=1;
	for(i=0;i<12;i++)
	{
		digits[i] = digits[i] + x;
		x = digits[i]/10;
		digits[i] = digits[i]%10;
	}
	for(i=9;i>=0;i--)
		printf("%d", digits[i]);
	printf("\n");
	return 0;
}
