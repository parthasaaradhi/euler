#include<stdio.h>
#include "hdr/107_input.h"
//#include "hdr/107_process.h"
#include "hdr/107_sorting.h"

int** p;

int main()
{
	int i,j;
	struct ans a;
	
	p = input();
	a = get_edges(p, 40);

	for(i=0;i<40;i++)
	{
		for(j=0;j<40;j++)
			printf("%d,", p[i][j]);
		printf("\n");
	}

	printf("Edges:\n");
	
	for(i=0;i<a.size;i++)
	{
		printf("%d:%d %d\n", a.e[i].x, a.e[i].y, a.e[i].w);
	}

	printf("\n...Start sorting\n");

	sort_edges_by_weight(a.e, a.size);

	for(i=0;i<a.size;i++)
		printf("%d ", a.e[i].w);

	printf("\n");

	return 0;
}
