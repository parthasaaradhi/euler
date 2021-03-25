#include<stdio.h>
#include<stdlib.h>
int** input_numbers()
{
	int **input_array = (int **) malloc(101*sizeof(int *));
	char c;
	int i,j,x;

	input_array[100] = (int *) malloc(100 * sizeof(int));
	
	for(i=0;i<100;i++)
	{
		j = 0;
		c = 'X';

		while(c != '\n')
		{
			x = 0;
			scanf("%c", &c);

			while(c != ',' && c!= '\n')
			{
				x = 10*x + (c - '0');
				scanf("%c", &c);
			}
			input_array[i] = (int *) realloc(input_array[i], (j+1)*sizeof(int));
			input_array[i][j] = x;
			j++;
		}

		input_array[100][i] = j;
	}

	return input_array;
}
