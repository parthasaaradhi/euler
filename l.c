#include<stdio.h>
#include<stdlib.h>
#include "hdr/107_sorting.h"

int a[7][7] = {
	{0,16,12,21,0,0,0},
	{16,0,0,17,20,0,0},
	{12,0,0,28,0,31,0},
	{21,17,28,0,18,19,23},
	{0,20,0,18,0,0,11},
	{0,0,31,19,0,0,27},
	{0,0,0,23,11,27,0}
};

int main()
{
	int i,j;
	int** p;
	struct ans b;
	
	p = malloc(7*sizeof(int *));
	for(i=0;i<7;i++)
	{
		p[i] = malloc(7*sizeof(int));
		for(j=0;j<7;j++)
			p[i][j] = a[i][j];
	}

	b = get_edges(p, 7);
	sort_edges_by_weight(b.e, b.size);
	for(i=0;i<b.size;i++)
		printf("%d ", b.e[i].w);
	printf("\n");


	return 0;
}

