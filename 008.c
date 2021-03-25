#include<stdio.h>
int main()
{
	int a[1000];
	char c;
	int i,j;
	long long max,p;
	max = 0;
	for(i=0;i<1000;i++)
	{
		scanf("%c", &c);
		if(c!='0' && c!='1' && c!='2' && c!='3' && c!='4' && c!='5'
				&& c!='6' && c!='7' && c!='8' && c!='9')
			i--;
		else
			a[i] = c - '0';
	}
	for(i=0;i<1000;i++)
	{
		p=1;
		for(j=0;j<13 && i+j<1000;j++)
			p=p*a[i+j];
		if(p>max)
			max=p;
	}
	printf("%lld\n", max);
	return 0;
}
