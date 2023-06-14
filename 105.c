#include<stdio.h>
#include<stdlib.h>
int total_subsets;
int set_size;
int* subsums;
int* trial;
void clean_slate() {
	int i;
	for(i=0;i<total_subsets;i++) subsums[i] = 0;
}
void compute_all_subsets(int idx) {
	int x=1;int i;
	if(idx == set_size)
		return;
	x = x<<idx;
	for(i=0;i<total_subsets;i++)
		if((i&x) != 0) {
			subsums[i] = subsums[i] + trial[idx];
		}
	compute_all_subsets(idx+1);
}
int no_elemets(int x) {
	int ans=0;
	while(x!=0) {
		ans = ans + x%2;
		x=x/2;
	}
	return ans;
}
int test_the_trial() {
	int i,j,in,jn;
	clean_slate();
	compute_all_subsets(0);
	for(i=1;i<total_subsets;i++) {
		for(j=i+1;j<total_subsets;j++)
			if((i&j)==0) {
				in=no_elemets(i);
				jn=no_elemets(j);
				if((in>jn && subsums[i]<=subsums[j]) || (in<jn && subsums[i]>=subsums[j]) || subsums[i]==subsums[j])
					return 1;
			}
	}
	return 0;
}
int main() {
	int i,j,ans,x;
	ans = 0;
	for(j=1;j<=100;j++) {
		scanf("%d", &set_size);
		total_subsets = 1 << set_size;
		trial = malloc(set_size*sizeof(int));
		subsums = malloc(total_subsets*sizeof(int));
		for(i=0;i<set_size;i++) scanf("%d", &trial[i]);
		x = test_the_trial();
		if(x==0)
			for(i=0;i<set_size;i++) ans = ans + trial[i];
		free(trial);
		free(subsums);
	}
	printf("%d\n", ans);
	return 0;
}
