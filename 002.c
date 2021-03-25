#include<stdio.h>
int main()
{
	long long N=4*1000*1000;
	long long sum=0;
	long long temp,first,second;
	first = 1; second = 2;
	while(second<=N) {
		sum = sum + (1-second%2)*second;
		temp = second;
		second = first + second;
		first = temp;
	}
	printf("%lld\n", sum);
	return 0;
}
