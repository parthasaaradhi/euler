#include<stdio.h>
int main()
{
	long long S[10000];
	long long i,j;
	for(i=0;i<10000;i++)
		S[i] = 1;
	for(i=2;i<10000;i++)
		for(j=2*i;j<10001;j=j+i)
			S[j] = S[j] + i;
	j=0;
	for(i=2;i<10000;i++)
		if(S[i] < 10000 && S[i] != i && S[S[i]] == i) {
			printf("%lld ", i);
			j=j+i;
		}
	printf("\n%lld\n", j);
	return 0;
}
