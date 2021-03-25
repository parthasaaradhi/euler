#include<stdio.h>
#define N 1000*1000
int main()
{
	int num[1000*1000];
	long long T=600851475143;
	int i,j;
	for(i=0;i<N;i++) num[i]=0;
	for(i=2;i<N;i++)
		if(num[i]==0)
			for(j=i*2;j<N;j=j+i)
				num[j]=1;
	for(i=N-1;i>1;i--)
		if(num[i] ==0 && T%i==0)
		{
			printf("%d\n", i);
			break;
		}
	return 0;
}
