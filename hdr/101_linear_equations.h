#include<stdlib.h>
#include "101_fraction.h"

void print_vector(struct fraction* b, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		fraction_print(b[i]);
		printf("\n");
	}
	return;
}

void print_matrix(struct fraction** a, int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fraction_print(a[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	return;
}
void multiply_matrix_scalar(struct fraction** a, struct fraction s, int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j] = fraction_multiply(a[i][j], s);
	return;
}

void multiply_vector_scalar(struct fraction* b, struct fraction s, int n)
{
	int i;
	for(i=0;i<n;i++)
		b[i] = fraction_multiply(b[i], s);
	return;
}

int transform(struct fraction** a, struct fraction* b, int n, int x, int y)
{
	int i,j;
	struct fraction inverse = fraction_inverse(a[x][y]);
	struct fraction nullifier;
	
	// No Inverse.
	if(a[x][y].n == 0)
		return 1;

	// Transform row so that the index of the current element is 1.
	for(i=0;i<n;i++)
		a[x][i] = fraction_multiply(a[x][i], inverse);
	b[x] = fraction_multiply(b[x], inverse);

	//Transform all other rows so that the corresponding element becomes zero
	for(i=x+1;i<n;i++)
	{
		nullifier = a[i][y]; // Since the original will change in the loop.
		b[i] = fraction_subtract(b[i], fraction_multiply(nullifier, b[x]));
		for(j=0;j<n;j++)
		{
			a[i][j] = fraction_subtract(a[i][j], fraction_multiply(nullifier, a[x][j]));
		}
	}
	return 0;
}

int reverse_transform(struct fraction** a, struct fraction* b, int n, int x, int y)
{
	int i,j;
	struct fraction inverse = fraction_inverse(a[x][y]);
	struct fraction nullifier;
	
	// No Inverse.
	if(a[x][y].n == 0)
		return 1;

	// Transform row so that the current index becomes 1.
	for(i=0;i<n;i++)
		a[x][i] = fraction_multiply(a[x][i], inverse);
	b[x] = fraction_multiply(b[x], inverse);
	// Transform all other rows so that the corresponding element becomes 0;
	for(i=x-1;i>=0;i--)
	{
		nullifier = a[i][y];
		b[i] = fraction_subtract(b[i], fraction_multiply(nullifier, b[x]));
		for(j=0;j<n;j++)
		{
			a[i][j] = fraction_subtract(a[i][j], fraction_multiply(nullifier, a[x][j]));
		}
	}
	return 0;
}

int solve_linear_equations(struct fraction** a, struct fraction* b, int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if( transform(a, b, n, i, i) == 1)
			return 1;
	}
	
	for(i=n-1;i>=0;i--)
	{
		if( reverse_transform(a,b,n,i,i) == 1)
			return 1;
	}

	return 0;
}
