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
int is_prime(int n) {
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0) return 1;
	return 0;
}

int main() {
	int n,cn,cnt,sum;
	n = 1;cn=0;cnt=0;;sum=0;
	do {
		n=n+2;
		if(n%5==0) n=n+2;
		cn = count(n);
		if(((n-1)%cn==0) && is_prime(n) !=0) {
			cnt++;
			sum=sum+n;
			//printf("%d %d\n", n, cn);
		}
	} while(cnt<25);
	printf("%d\n", sum);
	return 0;
}
