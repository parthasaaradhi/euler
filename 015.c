#include<stdio.h>
int main()
{
	long long s = 1;
	long long i;
	for(i=21;i<41;i=i+2)
		s = s*i;
	s = s * 1024;
	for(i=1;i<=10;i++)
		s = s/i;
	printf("%lld\n", s);
	return 0;
}
