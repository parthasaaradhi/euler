#include<stdio.h>
int count(int n) {
	int r,cnt;
	cnt=1;r=1%n;
	while(r!=0) {
		r = 10*r+1;
		r = r%n;
		cnt++;
	}
	return cnt;
}
int main() {
	int n,cn;
	n = 1000001-2;cn=0;
	do {
		n=n+2;
		if(n%5==0) n=n+2;
		cn = count(n);
		//printf("%d %d\n", n, cn);
	} while(cn<1000000);
	printf("%d\n", n);
	return 0;
}
