#include<stdlib.h>

int** input()
{
	int** p;
	int i,j,x;
	char c;

	p = malloc(40*sizeof(int *));

	for(i=0;i<40;i++)
	{
		p[i] = malloc(40*sizeof(int));

		for(j=0;j<40;j++)
		{
			x = 0;
			scanf("%c", &c);
			while(c != ',' && c!= '\n')
			{
				if(c != '-')
					x = 10*x + c - '0';
				scanf("%c", &c);
			}
			p[i][j] = x;
		}
	}
	return p;
}
