#include<stdio.h>
#include<stdlib.h>
int total_subsets;
int set_size;
int* subsums;
void clean_slate() {
	int i;
	for(i=0;i<total_subsets;i++) subsums[i] = 0;
}
void compute_all_subsets(int* trial, int idx) {
	int x=1;int i;
	if(idx == set_size)
		return;
	x = x<<idx;
	for(i=0;i<total_subsets;i++)
		if((i&x) != 0) {
			subsums[i] = subsums[i] + trial[idx];
		}
	compute_all_subsets(trial, idx+1);
}
int no_elemets(int x) {
	int ans=0;
	while(x!=0) {
		ans = ans + x%2;
		x=x/2;
	}
	return ans;
}
int test_the_trial(int* trial) {
	int i,j,in,jn;
	clean_slate();
	compute_all_subsets(trial, 0);
	for(i=1;i<total_subsets;i++) {
		for(j=i+1;j<total_subsets;j++)
			if((i&j)==0) {
				in=no_elemets(i);
				jn=no_elemets(j);
				//printf("Comparing %d %d %d : %d %d %d\n", i, in, subsums[i], j, jn, subsums[j]);
				if((in>jn && subsums[i]<=subsums[j]) || (in<jn && subsums[i]>=subsums[j]) || subsums[i]==subsums[j]) {
					//printf("Not ok\n");
					return 1;
				}
			}
	}
	return 0;
}
int main() {
	int i;
	int trial[7] = {20,31,38,39,40,42,45};
	set_size = 7;
	total_subsets = 1 << set_size;
	subsums = malloc(total_subsets*sizeof(int));	
	if(test_the_trial(trial)==0)
		for(i=0;i<set_size;i++)
		       printf("%d",trial[i]);
	printf("\n");
	free(subsums);
	return 0;
}
