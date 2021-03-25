#include<stdlib.h>
int** input_digits_call(int number_of_numbers, int number_of_digits)
{
	int** a = (int**) malloc(number_of_numbers * sizeof(int *));
	int i,j,x;
	for(i=0;i<number_of_numbers;i++)
		a[i] = (int *) malloc(number_of_digits * sizeof(int));
	char c;
	for(i=0;i<number_of_numbers;i++)
	{
		for(j=0;j<number_of_digits;j++)
		{
			scanf("%c", &c);
			a[i][j] = c - '0';
		}
		scanf("%c", &c);
	}
	return a;
}
