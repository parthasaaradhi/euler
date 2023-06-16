#include<stdio.h>
#include<stdlib.h>
#include "../implements/lib/matrix/matrix_long.h"
long long* actual_result;
long long** exponents;
struct fraction ans;

void print_array(long long** e) {
	long long i,j;
	for(i=0;i<11;i++) {
		for(j=0;j<11;j++)
			printf("%lld\t", e[i][j]);
		printf("\n");
	}
}

long long powers(long long n, long long x) {
	long long ans;
	ans = 1;
	while(x--) {
		ans = ans*n;
	}
	return ans;
}

long long given_polynomial(long long n) {
	//return powers(n,3);
	return ((powers(n,11) + 1)/(n+1));
}

void try_n(long long n) {
	struct matrix *A, *B;
	struct fraction temp;
	long long i;
	A = matrix_create(n,n,exponents);
	B = matrix_create_column(n,actual_result);
	matrix_solve_linear_equations(A,B);
	//fraction_set(&ans,0);
	//matrix_print(B);
	for(i=0;i<n;i++) {
		fraction_set(&temp, exponents[n][i]);
		fraction_mult(&temp, B->f[i], &temp);
		fraction_add(&ans, &ans, &temp);
	}
	//printf("%lld %lld\n", ans.numerator, given_polynomial(n+1));
	matrix_destroy(A);
	matrix_destroy(B);
}

int main() {
	long long i,j;
	exponents = malloc(11*sizeof(long long*));
	actual_result = malloc(11*sizeof(long long));

	for(i=0;i<11;i++)
		actual_result[i] = given_polynomial(i+1);
	for(i=0;i<11;i++) {
		exponents[i] = malloc(11*sizeof(long long));
		exponents[i][0]=1;
	}
	for(i=0;i<11;i++)
		for(j=1;j<11;j++)
			exponents[i][j] = exponents[i][j-1]*(i+1);
	//print_array(exponents);
	fraction_set(&ans, 0);
	for(i=1;i<11;i++)
		try_n(i);
	printf("%lld\n", ans.numerator);
	return 0;
}
