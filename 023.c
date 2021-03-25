#include<stdio.h>
int main()
{
	int a[28124];
	int i,j;
	for(i=0;i<28124;i++)
		a[i]=1;
	for(i=2;i<28124;i++)
		for(j=2*i;j<28124;j=j+i)
			a[j]+=i;
	j=0;
	for(i=2;i<28124;i++)
		if(a[i]>i)
			printf("%d\n", i);
	return 0;
}
