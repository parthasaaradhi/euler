#include<stdio.h>
#include<stdlib.h>

#include "hdr/105_input.h"
#include "hdr/105_spl_sub.h"

int main()
{
	int **v;
	int i,ans;

	v = input_numbers();
	ans = 0;
	
	for(i=0;i<100;i++)
		ans = ans + speacial_subset_test(v[100][i], v[i]);
	
	printf("%d\n", ans);
	return 0;
}
