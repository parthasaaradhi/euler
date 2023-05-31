#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
#include"../implements/general_inplace_merge_sort.h"
#define limit 100000000
int cpr(const void* a, const void* b) {
	long long* x = (long long*) a;
	long long* y = (long long*) b;
	return (*x)<(*y) ? -1 : 1;
}
int is_palindrome(long long n) {
	long long x,t;
	x=0;t=n;
	while(t!=0) {
		x = 10*x + t%10;
		t=t/10;
	}
	return x==n? 0 : 1;
}

int main() {
	long long a,b,n;
	long long* list;int s;
	mpz_t sum;
	mpz_init(sum);
	s=0;
	list = malloc(s*sizeof(long long));
	for(a=0;a<10000;a++) {
		n=(a+1)*(a+1);
		for(b=a+2;n<limit;b++) {
			n = n + b*b;
			if(n<limit && is_palindrome(n) == 0) {
				s++;
				list = realloc(list, s*sizeof(long long));
				list[s-1] = n;	
			}
		}
	}
	gip_merge_sort(list, s, sizeof(long long), cpr);
	mpz_set_ui(sum, 0);
	a=0;
	for(n=0;n<s;n++) {
		if(list[n] != a)
			mpz_add_ui(sum, sum,list[n]);
		a = list[n];
		//printf("%lld\n", list[n]);
	}
	gmp_printf("%Zd\n", sum);
	free(list);
	return 0;
}
