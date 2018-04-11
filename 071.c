#include<stdio.h>
int short_num;
int short_den;
int gcd(int n, int d) {
	if(d%n == 0)
		return n;
	return gcd(d%n, n);
}

void update_short(int n, int d) {
	//printf("%d: %d\n", n, d);
	if ( ((short_den*3 - 7*short_num)*d) > ((d*3 - 7*n)*short_den) ) {
		short_num = n;
		short_den = d;
	}
	return;
}
int main() {
	int n,d;
	short_num = 1;
	short_den = 8;
	for(d=1;d<=1000*1000;d++) {
		n = (3*d)/7;
		if(n*7 == 3*d) {
			n = n-1;
		}
		update_short(n, d);
	}
	printf("%d / %d : %d\n", short_num, short_den, gcd(short_num, short_den));
	return 0;
}
