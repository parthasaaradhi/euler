#include<stdio.h>
int main()
{
	int temp[1000];
	int prev[1000];
	int next[1000];
	int i,carry,n;
	for(i=0;i<1000;i++)
		prev[i] = next[i] = 0;
	prev[999] = next[999] = 1;
	n = 2;
	while(next[0] == 0)
	{
		n++;
		carry = 0;
		for(i=999;i>=0;i--)
			temp[i]=next[i];
		for(i=999;i>=0;i--)
		{
			next[i] = (carry+temp[i]+prev[i])%10;
			carry = (carry+temp[i]+prev[i])/10;
		}
		for(i=999;i>=0;i--)
			prev[i]=temp[i];
		/*for(i=0;i<1000;i++)
			printf("%d", next[i]);
		printf("\n");*/
	}
	printf("%d\n", n);
	return 0;
}
