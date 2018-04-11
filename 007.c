#include<stdio.h>
int main()
{
	long long myprimes[10001];
	myprimes[0] = 2;
	long long num = 3;
	int x = 0;
	int i;

	while(x != 10000)
	{
		i = 0;
		while(i<=x)
		{
			if (num % myprimes[i] == 0) {
				num = num + 1;
				i = 0;
			} else {
				i = i + 1 ;
			}
		}
		myprimes[x+1] = num;
		x = x + 1;
	}
	printf("%lld, %lld\n", myprimes[5], myprimes[10000]);
	return 0;
}
