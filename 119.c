#include<stdio.h>
#include<stdlib.h>
#include"../implements/general_inplace_merge_sort.h"
int cpr(const void* a, const void* b) {
	unsigned long long *x = (unsigned long long *) a;
	unsigned long long *y = (unsigned long long *) b;
	return *x<*y ? -1 : 1;
}
unsigned long long digit_sum(unsigned long long n) {
	unsigned long long x = 0;
	while(n!=0) {
		x = x + n%10;
		n = n/10;
	}
	return x;
}

void check_and_fill(unsigned long long n, unsigned long long *ptr, int* s) {
	unsigned long long pro;
	pro = n;
	while((*s)<30 && pro < 1000000000000000) {
		if(pro>10 && digit_sum(pro) == n) {
			(*s)++;
			//ptr = realloc(ptr, (*s)*sizeof(unsigned long long));
			ptr[(*s)-1] = pro;
			//printf("%lld %lld %d\n", pro, n, (*s));
		}
		pro = pro * n;
	}
}

int main() {
	unsigned long long dc,ds,n;
	unsigned long long answers[30];int size;
	for(n=0;n<30;n++) answers[n] = 0;
	n = 2;
	size = 0;
	while(size<30 && n<10000000) {
		check_and_fill(n,answers, &size);
		n++;
	}
	gip_merge_sort(answers, 30, sizeof(unsigned long long), cpr);
	//for(n=0;n<35;n++) printf("%lld\n", answers[n]);
	printf("%lld\n", answers[29]);
	return 0;
}
