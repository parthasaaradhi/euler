#include<stdio.h>
int main()
{
	int m,a,x,y,i;
	int num[4];
	int den[4];
	i=0;
	for(m=10;m<99;m++)
	{
		if (m%10 != 0) {
			x = m%10;
			y = m/10;
			for(a=1;a<10;a++) {
				if((a*10+x)*y == m*a && (a*10+x) > m) {
					num[i] = y;
					den[i] = a;
					i++;
					//printf("%d : %d\n", m, a*10+x);
				}
				if((a*10+y)*x == m*a && (a*10+y) > m) {
					num[i] = x;
					den[i] = a;
					i++;
					//printf("%d : %d\n", m, a*10+y);
				}
				if((x*10+a)*y == m*a && (x*10+a) > m) {
					num[i] = y;
					den[i] = a;
					i++;
					//printf("%d : %d\n", m, x*10+a);
				}
				if((y*10+a)*x == m*a && (y*10+a) > m) {
					num[i] = x;
					den[i] = a;
					i++;
					//printf("%d : %d\n", m, y*10+a);
				}
			}
		}

	}
	m = a = 1;
	for(i=0;i<4;i++) {
		m = m*num[i];
		a = a*den[i];
	}
	printf("%d: %d\n", m, a);
	return 0;
}
