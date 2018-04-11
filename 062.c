#include<stdio.h>
int digits[10];
unsigned long long cube_root(unsigned long long n) {
	if(n == 0)
		return 0;
	long long x;
	x = n/(3500*3500);
	while(!((n==(x*x*x)) || (n > (x*x*x) && (n < ((x+1)*(x+1)*(x+1)))))) {
		x = ((n/(x*x)) + (2*x))/3;
		//printf("%lld ", x);
	}
	if(n == x*x*x) {
		//printf("%lld ", x);
		return x;
	}
	return 0;
}

int cube_count_of_permutations(unsigned long long n) {
	int i,x,finished;
	x = 0;
	finished = 0;
	i = 9;
	// First digit cannot be 0
	while((i>-1 && n!=0) || (i>0 && n==0)) {
		if(digits[i] > 0) {
			finished = 1;
			digits[i]--;
			x = x + cube_count_of_permutations(10*n+i);
			digits[i]++;
		}
		i--;
	}
	if(finished == 0) {
		//printf("%lld\n", n);
		x = x + (cube_root(n)==0 ? 0 : 1); 
	}
	return x;
}

void refresh_digits(unsigned long long n) {
	int i;
	for(i=0;i<10;i++)
		digits[i] = 0;
	while(n!=0) {
		digits[n%10]++;
		n = n/10;
	}
	return;
}

int main()
{
	unsigned long long n;
	int x;
	x = 0;
	n = 5000;
	while(x != 5) {
		refresh_digits(n*n*n);
		x = cube_count_of_permutations(0);
		printf("Count: %d Cube: %lld\n", x, n);
		n++;
	}
	return 0;
}
