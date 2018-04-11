#include<stdio.h>
int main()
{
	int seive[10000];
	int i,j,n;
	n = 3;
	seive[0] = -1;
	seive[1] = 1;
	for(i=2;i<10000;i++)
		seive[i] = 0;
	for(i=2;i<100;i++) {
		if (seive[i] == 0) {
			for(j=i*i;j<10000;j=j+i)
				seive[j] = 1;
		}
	}
	while(n<10000) {
		//printf("%d\n", n);
		if(seive[n] == 1) {
			i = 1;
			while((n-2*i*i) > 0) {
				if(seive[n-2*i*i] == 1) {
					//printf("Try %d : %d\n", n, i);
					i++;
				} else {
					//printf("%d : %d\n", n, i);
					break;
				}
			}
			if(n-2*i*i < 0) {
				printf("%d\n", n);
				return 0;
			}
		}
		n=n+2;
	}
	return 0;
}
