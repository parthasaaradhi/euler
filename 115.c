#include<stdio.h>
#include<stdlib.h>
int main() {
	int* r; int n,m,i,t;
	m=50;
	//scanf("%d", &m);
	r = malloc((m+1)*sizeof(int));
	for(i=0;i<m;i++) r[i] = 1;
	r[m-1] = 2;
	r[m] = 4;
	n = m+1;
	while(r[m]<=1000000) {
		t = r[m];
		r[m] = 2*r[m]-r[m-1]+r[0];
		for(i=0;i<m;i++)
			r[i] = r[i+1];
		r[m-1] = t;
		n++;
	}
	printf("%d\n", n);
	free(r);
	return 0;
}
