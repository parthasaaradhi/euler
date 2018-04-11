#include<stdio.h>
// To have n digits for m^n
//10^(n-1) < m^n < 10^n 
// m < 10
// n < 1 / (1 - log n)
// n < 1 / (1 - log 9)
// n < 1 / (1 - 0.954242509)
// n < 21.8 => n < 22

int main() {
	int digits[25];
	int i,m,n,x,carry;
	x = 0;
	// Just doing it for all.
	for(m=1;m<10;m++) {
		for(i=24;i>-1;i--)
			digits[i] = 0;
		digits[24] = m;
		x++;
		for(n=2;n<24;n++) {
			carry = 0;
			for(i=24;i>-1;i--) {
				digits[i] = digits[i]*m + carry;
				carry = digits[i]/10;
				digits[i] = digits[i]%10;
			}
			i=0;
			while(digits[i]==0)
				i++;
			if(25-i == n)
				x++;
		}
	}
	printf("%d\n", x);
}
