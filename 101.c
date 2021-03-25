#include<stdio.h>
#include "stdlib.h"
#include "hdr/101_linear_equations.h"

/*
long long my_power(long long n, int i)
{
	long long x = 1;
	while(i!=0)
	{
		x = n*x;
		i--;
	}
	return x;
}
*/

long long evaluate_polynomial_expression(long long * a, int n, long long x)
{
	// a[0] + a[1] x + a[2] x^2 + a[3] x^3 + ... + a[n] x^n
	int i;
	long long p = 1;
	long long ans = 0;
	for(i=0;i<n+1;i++)
	{
		ans = ans + a[i]*p;
		p = p*x;
	}
	return ans;
}

int main()
{
	long long n;
	long long* exp;
	long long** system_of_equations;
	long long* end_vector;
	struct fraction** A;
	struct fraction* b;

	exp = malloc(11*sizeof(long long));
	system_of_equations = malloc(5*sizeof(long long *));
	end_vector = malloc(5*sizeof(long long));

	int i;

	for(n=1;n<6;n++)
	{
		system_of_equations[n-1] = malloc(5*sizeof(long long));
		system_of_equations[n-1][0] = 1;
		for(i=1;i<5;i++)
			system_of_equations[n-1][i] = system_of_equations[n-1][i-1]*n;
	}

	exp[0] = 1;

	for(i=1;i<11;i++)
		exp[i] = -1*exp[i-1];

	for(n=1;n<6;n++)
	{
		end_vector[n-1] = evaluate_polynomial_expression(exp, 10, n);
		printf("%lld\n", end_vector[n-1]);
	}

	for(n=0;n<5;n++)
	{
		for(i=0;i<5;i++)
			printf("%lld ", system_of_equations[n][i]);
		printf("%lld\n", end_vector[n]);
	}

	A = convert_long_fraction_matrix(system_of_equations, 5);
	b = convert_long_fraction_vector(end_vector, 5);

	solve_linear_equations(A, b, 5);

	print_matrix(A, 5);
	print_vector(b, 5);

	return 0;
}
