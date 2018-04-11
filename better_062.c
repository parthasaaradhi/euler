#include<stdio.h>
int current_n_cube[10];
void refresh_n(long long n) {
	int i;
	for(i=0;i<10;i++)
		current_n_cube[i] = 0;
	while(n!=0) {
		current_n_cube[n%10]++;
		n=n/10;
	}
}

int is_permutation(long long m) {
	int m_digits[10];
	int i;
	for(i=0;i<10;i++)
		m_digits[i] = 0;
	while(m!=0) {
		m_digits[m%10]++;
		m=m/10;
	}
	for(i=0;i<10;i++) {
		if (m_digits[i] != current_n_cube[i])
			return 0;
	}
	return 1;
}

int main() {
	long long n,m;int x;
	n=1;
	while(x!=4) {
		refresh_n(n*n*n);
		x=0;
		m = n + 1;
		while(m*m*m <= 10*n*n*n) {
			x = x + is_permutation(m*m*m);
			m++;
			if(x>4)
				break;
		}
		n++;
	}
	n--;
	printf("Cube of %lld: %lld\n", n, n*n*n);
	return 0;
}
