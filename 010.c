#include<stdio.h>
int main()
{
	long long myprimes[1000000];
	long long digits[30];
	int x = 1;
	int i,j;
	myprimes[0] = 2;
	myprimes[1] = 3;
	long long n = 5;
	long long carry = 5;
	long long N = 2 * 1000 * 1000;
	digits[0] = 5;
	for(j=1;j<30;j++) {
		digits[j] = 0;
	}
	while(n <= N) {
		while(i<=x && n <= N) {
			if(n%myprimes[i] == 0) {
				n = n + 2;
				i = 1;
			} else {
				i = i + 1;
			}
		}
		if ( n <= N ) {
			myprimes[x+1] = n;
			carry = carry + n;
			/*
			while(carry != 0) {
				digits[j] = (digits[j] + carry)%10;
				carry = (digits[j] + carry)/10;
				printf("%d\n", digits[j]);
				j = j + 1;
			}*/
			n = n + 2;
			x = x + 1;
			i = 1;
		}
	}
	printf("%d\n", x);
	/*
	for(j=29;j>=0;j--)
		printf("%lld", digits[j]);*/
	printf("%lld\n", carry);
	return 0;
}
