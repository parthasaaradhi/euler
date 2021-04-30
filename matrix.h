#ifndef MATRIX_H
#define MATRIX_H
#include<stdlib.h>
#include "numbers.h"

void print_matrix(struct number** A, int r, int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			number_print(&A[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}

void print_column(struct number* B, int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		printf("\t");
		number_print(&B[i]);
		printf("\n");
	}
	//printf("\n");
}

void transform(struct number** A, struct number* B, int n, int diagonal)
{
	int i,j;
	struct number* tmp_i_d;
	struct number* tmp_i_j;
	struct number* tmp_mult;
	struct number* tmp_sub;

	for(i=diagonal+1;i<n;i++)
	{
		tmp_i_d = malloc(sizeof(struct number));
		number_copy(tmp_i_d, &A[i][diagonal]);

		for(j=diagonal;j<n;j++)
		{
			tmp_mult = multiply_numbers(&A[diagonal][j], tmp_i_d);
			
			tmp_i_j = multiply_numbers(&A[i][j], &A[diagonal][diagonal]);
			
			tmp_sub = subtract_numbers(tmp_i_j, tmp_mult);
			
			number_copy(&A[i][j], tmp_sub);

			free(tmp_mult);
			free(tmp_i_j);
			free(tmp_sub);
		}

		tmp_mult = multiply_numbers(&B[diagonal], tmp_i_d);
		tmp_i_j = multiply_numbers(&B[i], &A[diagonal][diagonal]);
		tmp_sub = subtract_numbers(tmp_i_j, tmp_mult);

		number_copy(&B[i], tmp_sub);

		free(tmp_mult);
		free(tmp_i_j);
		free(tmp_sub);
		free(tmp_i_d);
	}
	return;
}

void reverse_transform(struct number** A, struct number* B, int n, int diagonal)
{
	int i,j;
	struct number* tmp_i_d;
	struct number* tmp_i_j;
	struct number* tmp_mult;
	struct number* tmp_sub;
	
	for(i=diagonal-1;i>=0;i--)
	{
		tmp_i_d = malloc(sizeof(struct number));
		number_copy(tmp_i_d, &A[i][diagonal]);

		for(j=0;j<n;j++)
		{
			tmp_mult = multiply_numbers(&A[diagonal][j], tmp_i_d);

			tmp_i_j = multiply_numbers(&A[i][j], &A[diagonal][diagonal]); 

			tmp_sub = subtract_numbers(tmp_i_j, tmp_mult);

			number_copy(&A[i][j], tmp_sub);

			free(tmp_mult);
			free(tmp_i_j);
			free(tmp_sub);
		}

		tmp_mult = multiply_numbers(&B[diagonal], tmp_i_d);
		tmp_i_j = multiply_numbers(&B[i], &A[diagonal][diagonal]);
		tmp_sub = subtract_numbers(tmp_i_j, tmp_mult);

		number_copy(&B[i], tmp_sub);

		free(tmp_mult);
		free(tmp_i_j);
		free(tmp_sub);
		free(tmp_i_d);
	}
	return;
}

void solve(struct number** A, struct number* B, int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		transform(A, B, n, i);
		//print_matrix(A, n, n);
		//print_column(B, n);
	}
	for(i=n-1;i>0;i--)
	{
		reverse_transform(A, B, n, i);
		//print_matrix(A, n, n);
		//print_column(B, n);
	}
	return;
}

#endif
