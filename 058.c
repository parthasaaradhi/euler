#include<stdio.h>
char seive[175*175];
void fill_primes() {
	int i,j;
	for(i=2;i<175*175;i++)
		seive[i] = '1';
	for(i=2;i<175;i++)
		if(seive[i] == '1')
			for(j=i*i;j<175*175;j=j+i)
				seive[j] = '0';
	return;
}

int is_prime(int n) {
	int i;
	if (n<175*175) {
		return seive[n] - '0';
	} else {
		for(i=2;i<175*175;i++)
			if(seive[i] == '1' && n%i == 0)
				return 0;
		return 1;
	}
}

int main() {
	int n,s,p,sq;
	n = 1;
	s = 1;
	sq = 1;
	p = 0;
	fill_primes();
	while(10*p >= sq || p==0) {
		p = p + is_prime(s + (n+1)) + is_prime(s + 2*(n+1)) + is_prime(s + 3*(n+1));// + is_prime(s + 4*(n+1));
		sq=sq+4;
		//printf("%lld %lld %lld %lld\n", s + n+1, s + 2*(n+1), s + 3*(n+1), s + 4*(n+1));
		s = s + 4*(n+1);
		n=n+2;
	}
	printf("%d/%d %d\n", p, sq, s);
	return 0;
}
