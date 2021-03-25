#include<stdio.h>
int main()
{
	int digits[10];
	int a[10];
	int i;
	int N=1000*1000;
	a[0]=1;
	for(i=0;i<10;i++)
		digits[i]=0;
	for(i=1;i<10;i++)
		a[i]=i*a[i-1];
	for(i=9;i>-1;i--)
	{

	}
	return 0;
}
