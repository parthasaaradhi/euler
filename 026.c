#include<stdio.h>
int main()
{
	int d,n,i;
	int div[1000];
	int s;
	int m=0;
	int N = 1;
	for(d=2;d<1000;d++) {
		n = 1;
		for(i=0;i<1000;i++)
			div[i] = 0;
		while(div[n] != 2 && n != 0) {
			div[n] = div[n] + 1;
			n = n * 10;
			n = n%d;
		}
		if (n != 0) {
			s = 1;
			//printf("For the number %d:\t", d);
			i = n * 10;
			//printf("%d", i/d);
			i = i%d;
			while(i != n) {
				i = i * 10;
				//printf("%d", i/d);
				i = i%d;
				s++;
			}
			N = s>m ? d : N;
			m = s>m ? s : m;
			//printf("%d\n", s);
		}
	}
	printf("%d\n", N);
	return 0;
}
