#include<stdio.h>
int original[10];
int mult[10];

void fillOrig(long long n)
{
	int i;
	for(i=0;i<10;i++)
		original[i] = 0;
	while(n!=0)
	{
		original[n%10]++;
		n/=10;
	}
	return;
}

void fillMult(long long n)
{
	int i;
	for(i=0;i<10;i++)
		mult[i] = 0;
	while(n!=0)
	{
		mult[n%10]++;
		n=n/10;
	}
	return;
}

int test(long long n)
{
	int i;
	fillMult(n);
	for(i=0;i<10;i++)
		if(original[i] != mult[i])
			return 1;
	return 0;
}
int main()
{
	long long n;
	int i,f=0;
	n = 0;
	while(f!=5) {
		f=0;
		n=n+3;
		fillOrig(n);
		for(i=2;i<7;i++)
			if (test(i*n) == 0)
				f++;
			else
				break;
	}
	printf("%lld\n", n);
	return 0;
}
