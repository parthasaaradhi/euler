#include<stdio.h>
#include<stdlib.h>
#include"../implements/lib/fraction/fraction_long.h"
struct fraction calculate(struct fraction* b, struct fraction* r, int n, int idx) {
	struct fraction ans,temp;
	fraction_set(&ans, 0);
	fraction_set(&temp, 0);
	if(idx==15) {
		ans.numerator = n==0? 1 : 0;
	} else {
		if(n>0) {
			temp = calculate(b,r,n-1,idx+1);
			fraction_mult(&temp, &temp, &(b[idx]));
			fraction_add(&ans, &ans, &temp);
		}
		temp = calculate(b,r,n,idx+1);
		fraction_mult(&temp,&temp,&(r[idx]));
		fraction_add(&ans, &ans, &temp);	
	}
	return ans;
}
int main() {
	int i; struct fraction ans,temp;
	fraction_set(&ans, 0);
	struct fraction blues[15];
	struct fraction reds[15];
	for(i=0;i<15;i++) {
		blues[i].numerator = 1;
		blues[i].denominator = i+2;
		reds[i].numerator = i+1;
		reds[i].denominator = i+2;
	}
	for(i=8;i<=15;i++) {
		temp = calculate(blues, reds, i, 0);
		fraction_add(&ans, &ans, &temp);
	}
	printf("%lld\n", ans.denominator/ans.numerator);
	return 0;
}
