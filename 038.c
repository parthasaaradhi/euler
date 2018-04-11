#include<stdio.h>
int main()
{
	int digits[9];
	int i,n,m,j,x,f;
	for(n=1;n<1000000;n++) {
		i = 1;
		f = 0;
		x=0;
		for(j=0;j<9;j++)
			digits[j] = 0;
		while(x<9 && f==0) {
			m = n*i;
			while(m!=0) {
				x++;
				if (m%10 == 0) {
					f = 1;
					break;
				} else {
					digits[m%10 - 1]++;
					m=m/10;
				}
			}
			i++;
		}
		for(j=0;j<9;j++)
			if(digits[j] != 1)
				f = 1;
		if (f == 0) {
			printf("%d:\t", n);
			for(x=1;x<i;x++)
				printf("%d", n*x);
			printf("\n");
		}
	}
	return 0;
}
