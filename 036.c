#include<stdio.h>
int main()
{
	int n,m,i;
	long long s;
	n = 1;
	s = 0;
	while(n <1000*1000) {
		i = n;
		m = 0;
		while(i!=0) {
			m = i%10 + m*10;
			i = i/10;
		}
		if (m == n) {
			//printf("%d\n", m);
			i = n;
			m = 0;
			while(i!=0) {
				m = i%2 + (m << 1);
				i = i >> 1;
			}
			if (m == n)
				s = s + n;
				//printf("%d\n", n);
		}
		n++;
	}
	printf("%lld\n", s);
	return 0;
}
