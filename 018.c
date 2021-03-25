#include<stdio.h>
#include<stdlib.h>

int sig_n(int n){
	return n*(n+1)/2;
}

int main()
{
	int n,i,j;
	int* a;
	n=15;
	a = (int*) malloc((sig_n(n)+1)*sizeof(int));
	for(i=0;i<sig_n(n);i++)
		scanf("%d", &a[i]);
	// We are on the n-1 line. (n-2)*(n-1)/2 is the index of the first number in this line.
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			a[sig_n(i-1)+j] = a[sig_n(i-1)+j] + (a[sig_n(i)+j] > a[sig_n(i)+j+1] ? a[sig_n(i)+j] : a[sig_n(i)+j+1]);
		}
	}
	printf("%d\n", a[0]);
	return 0;
}
