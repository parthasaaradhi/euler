#include<stdio.h>
int main()
{
	int a[500];
	int i,n,carry;
	for(i=0;i<500;i++)
		a[i]=0;
	a[499]=1;
	n=1;
	while(n<101)
	{
		carry=0;
		for(i=499;i>-1;i--)
		{
			a[i] = a[i]*n+carry;
			carry=a[i]/10;
			a[i] = a[i]%10;
		}
		n++;
	}
	carry=0;
	for(i=499;i>-1;i--)
		carry = carry + a[i];
		//printf("%d",a[i]);
	printf("%d\n", carry);
	return 0;
}
