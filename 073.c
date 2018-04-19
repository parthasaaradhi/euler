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
	if ((d*(short_num*3-short_den)) > (short_den*(3*n-d)))
	{
		short_num = n;
		short_den = d;
	}
	return;
}
int main() {
	int n,d,n1,d1,temp_n,temp_d,x;
	short_num = 1;
	short_den = 2;
	for(d=1;d<=12*1000;d++) {
		n = d/3 + 1;
		update_short(n, d);
	}
	x = gcd(short_num, short_den);
	short_num = short_num / x;
	short_den = short_den / x;
	printf("%d / %d\n", short_num, short_den);
	x = 0;
	n = 1;
	d = 3;
	n1 = short_num;
	d1 = short_den;
	temp_n;
	temp_d;
	while(!(n1 == 1 && d1 == 2)) {
		temp_n = n1;
		temp_d = d1;
		n1 = ((12000+d)/d1)*n1 - n;
		d1 = ((12000+d)/d1)*d1 - d;
		n = temp_n;
		d = temp_d;
		x++;
	}
	printf("%d\n", x);
	return 0;
}
