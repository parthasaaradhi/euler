#include<stdio.h>
#define PRIME_MAX 4800
#define MY_MAX 47000
#define DIVISOR 1000000000

int fibo[24];
long long sumsPrimes[MY_MAX][PRIME_MAX];
int myprimes[PRIME_MAX];

void fillPrimes() {
	myprimes[0] = 2;
	myprimes[1] = 3;
	int n = 5;
	int x,i;
	x=1;i=1;
	while (x < PRIME_MAX-1) {
		while(i<=x) {
			if (n%myprimes[i] == 0) {
				n = n + 2;
				i = 1;
			} else {
				i = i + 1;
			}
		}
		myprimes[x+1] = n;
		x = x + 1;
		i = 1;
	}
	//for(i=0;i<PRIME_MAX;i++)
	//	printf("%lld\t", myprimes[i]);
	printf("\n");
}

void fillFibo() {
	fibo[0] = 1;
	fibo[1] = 1;
	int i = 2;
	while(i<24) {
		fibo[i] = fibo[i-1] + fibo[i-2];
		//printf("FIBO: %d\t%d\n", i+1, fibo[i]);
		i++;
	}
}


long long findSum(int n, int p) {
	//printf("%d, %d\n", n, p);
	int i,nn;
	long long ans = 0;
	if (sumsPrimes[n][p] != -1) {
		return sumsPrimes[n][p];
	} else {
		if ( n == myprimes[p] ) {
			return n;
		}
		if (n<myprimes[p]) {
			sumsPrimes[n][p] = 0;
			return 0;
		}
		nn = n - myprimes[p];
		for(i=p;i<PRIME_MAX && nn >= myprimes[i];i++)
			ans = (ans + (myprimes[p]*findSum(nn, i))%DIVISOR)%DIVISOR;
		sumsPrimes[n][p] = ans;
		return ans;
	}
}

int main()
{
	fillPrimes();
	fillFibo();
	int i=0;int j=0;
	long long ans = 0;
	for(i=0;i<MY_MAX;i++) {
		for(j=0;j<PRIME_MAX;j++) {
			sumsPrimes[i][j] = -1;
		}
	}
	for(i=0;i<24;i++) {
		j = PRIME_MAX - 1;
		while(myprimes[j] < fibo[i])
			j--;
		while(j>=0) {
			ans = (ans + findSum(fibo[i], j))%DIVISOR;
			j--;
		}
	}
	printf("LULZ: %lld\n", ans);
	return 0;

}
