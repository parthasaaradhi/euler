#include<stdio.h>
int main()
{
	int seive[1000000];
	int i,j;
	for(i=2;i<1000000;i++)
		seive[i] = 0;
	for(i=2;i<1000000;i++)
		if(seive[i] == 0)
			for(j=2*i;j<1000000;j=j+i)
				seive[j] = seive[j]+1;
	for(i=2;i<999996;i++)
		if(seive[i] == 4 && seive[i+1] == 4 && seive[i+2] == 4 && seive[i+3] == 4)
		{
			printf("%d\n", i);
			return 0;
		}

	return 0;
}
