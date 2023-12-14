#include<stdio.h>
long long mill = 1000000;
long long gcd(long long q, long long p) {
	if(q==0) return p;
	return gcd(p%q, q);
}
long long is_perfect_square(long long n) {
	long long s;
	s=1;
	while(s*s<n) s++;
	return s*s==n ? s : 0;
}
int main() {
	long long a,p,q,g,n;
	char tested[mill];
	for(a=0;a<mill;a++) tested[a] = '0';
	for(a=1;a<mill;a++) {
		for(q=1;q*q<=a;q++) {
			if((a%(q*q)==0) && ((a*a)%(q*q*q) == 0)) {
				n=0;
				for(p=q+1;n<mill*mill;p++) {
					n = ((a*a)/(q*q*q))*(p*p*p) + a;
					if(n<mill*mill) {
						g = is_perfect_square(n);
						if(g!=0) {
							printf("%lld\n", n);
							tested[g-1] = '1';
						}
					}
				}
			}
		}
	}
	for(a=0;a<mill;a++)
		if(tested[a] == '1')
			printf("%lld\n", a*a);
	return 0;
}
