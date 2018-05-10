#include<stdio.h>
#define N 1000000
int main()
{
	int p[100000];
	int i,j;
	p[0] = 1; p[1] = 1;
	for(i=2;i<100000;i++)
		p[i] = 0;
	for(i=2;i<100000;i++)
	{
		j = 1;
		while(i >= ((j*(3*j-1))/2)) {
			if(j%2!=0)
			{
				p[i] = (p[i] + p[i - ((j*(3*j-1))/2)])%N;
			} else {
				p[i] = (p[i] - p[i - ((j*(3*j-1))/2)])%N;
			}
			if(p[i]<0)
				p[i] = N + p[i];
			if(j>0) {
				j = 0-j;
			}
			else {
				j = 1-j;
			}
		}
		if (p[i] == 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	for(i=0;i<100000;i++)
		printf("%d: %d\n", i, p[i]);
	return 0;
}
