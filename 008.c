#include<stdio.h>
int main()
{
	int A[1000];
	long long ip = 0;
	int i=0;
	int j;
	long long m = 0;
	char c = '0';
	for(j=0;j<1000;){
		scanf("%c", &c);
		if ( c > 47 && c < 58) {
			A[j] = c - 48;
			j = j + 1;
		}
	}
	while(i<1000-13) {
		if (ip == 0) {
			ip = 1;
			for(j=i;j<i+13;j++) {
				if ( A[j] == 0) {
					i = j + 1;
					ip = 0;
					break;
				} else {
					ip = ip * A[j];
				}
			}
			if (ip != 0) {
				printf("%d, %lld\n", i, ip);
				i = i + 1;
			}
		} else {
			if (A[i+12] == 0) {
				ip = 0;
				i = i + 13;
			} else {
				ip = ip / A[i-1] * A[i + 12];
				printf("%d, %lld\n", i, ip);
				i = i + 1;
			}
		}
		if (m < ip)
			m = ip;
	}
	printf("%lld\n", m);
	return 0;
}
