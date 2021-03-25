#include<stdio.h>
int main()
{
	int a[350];
	int i,carry,n;
	a[0]=1;
	for(i=1;i<350;i++)
		a[i]=0;
	n=0;
	while(n<1000)
	{
		carry = 0;
		for(i=0;i<350;i++)
		{
			a[i] = 2*a[i]+carry;
			carry = a[i]/10;
			a[i] = a[i]%10;
		}
		n++;
	}
	n=0;
	for(i=349;i>-1;i--)
		n=n+a[i];
	printf("%d\n", n);
	return 0;
}
