#include<stdio.h>
long long primes[10000];
long long answer(long long n) {
	long long i,x,y,ans;
	x = n;
	ans = 1;
	for(i=2;i<10000;i++)
		if(primes[i] != 0) {
			y=0;
			while(x%i == 0) {
				x = x/i;
				y++;
			}
			ans = ans * (2*y+1);
		}
	if(ans%2!=0) ans++;
	return ans/2;

}

void fill_primes() {
	long long i,j;
	for(i=0;i<10000;i++) primes[i] = 1;
	for(i=2;i<100;i++)
		if(primes[i] == 1)
			for(j=2*i;j<10000;j=j+i) primes[j] = 0;
	return;
}

int main() {
	long long i;
	fill_primes();
	i=4;
	while(answer(i) <= 4000000) {
		i++; printf("%lld\n", i);
	}
	return 0;
}
