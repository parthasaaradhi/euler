#include<stdio.h>
#include "hdr/105_spl_sub.h"

int main()
{
	int i;
	int a[7] = {20, 31, 38, 39, 40, 42, 45};
	if (speacial_subset_test(7, a) != 0)
		for(i=0;i<7;i++)
			printf("%d", a[i]);
	printf("\n");
}
