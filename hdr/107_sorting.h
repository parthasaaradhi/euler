#include "107_process.h"

void inplace_merge_sort(struct edge* e, int s,int f)
{
	int l,k,i;
	struct edge* temp;

	if(f-s==1 || f-s==0)
		return;

	l = s;
	k = (s+f)/2;

	inplace_merge_sort(e, l, k);
	inplace_merge_sort(e, k, f);

	temp = malloc((f-s)*sizeof(struct edge));

	for(i=0;i<f-s;i++)
	{
		if(k == f)
		{
			temp[i] = e[l];
			l++;
		}
		
		else if(l == (s+f)/2)
		{
			temp[i] = e[k];
			k++;
		}

		else {

			if(e[l].w < e[k].w){
				temp[i] = e[l];
				l++;
			}
			else {
				temp[i] = e[k];
				k++;
			}
		}

	}
	
	for(i=s;i<f;i++)
		e[i] = temp[i-s];
	
	free(temp);
	temp = NULL;
	return;
}

void sort_edges_by_weight(struct edge* e, int size)
{
	inplace_merge_sort(e, 0, size);
	return;
}


