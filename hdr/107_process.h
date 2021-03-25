#include<stdlib.h>

struct edge
{
	int x;
	int y;
	int w;
};

struct ans 
{
	struct edge* e;
	int size;
};

struct ans get_edges(int** p, int v)
{
	int i,j,n;
	struct edge* e;
	struct ans a;

	n = 0;
	e = malloc(0);

	for(i=0;i<v;i++)
		for(j=i+1;j<v;j++)
			if(p[i][j] != 0)
			{
				e = (struct edge* )realloc(e, (n+1)*sizeof(struct edge));
				e[n].x = i;
				e[n].y = j;
				e[n].w = p[i][j];
				n++;
			}
	a.size = n;
	a.e = e;
	return a;
}
