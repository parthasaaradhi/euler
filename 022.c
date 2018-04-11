#include<stdio.h>
#include<string.h>
char names[6000][50];
char temps[6000][50];
int compare(int x, int y)
{
	int j=0;
	int xl = strlen(names[x]);
	int yl = strlen(names[y]);
	while(j < xl && j < yl) {
		if (names[x][j] > names[y][j])
			return y;
		else if (names[x][j] < names[y][j])
			return x;
		else
			j++;
	}
	return (j == xl) ? x : y;
}
void mergeSort(int in, int fi)
{
	if (in == fi)
		return;
	int len;
	int ltend;
	int i, j, x;
	len = fi + 1 - in;
	if (len%2 == 0) {
		ltend = in + len/2 -1;
	} else {
		ltend = in + (len-1)/2;
	}
	mergeSort(in, ltend);
	mergeSort(ltend+1, fi);
	i = in; j = ltend+1; x = in;
	while(x <= fi) {
		len = (i>ltend)? j : ((j>fi)? i : compare(i,j));
		strcpy(temps[x], names[len]);
		x++;
		if (len == j)
			j++;
		else
			i++;
	}
	for(i=in;i<=fi;i++)
		strcpy(names[i], temps[i]);
	return;
}
int main()
{
	char c;
	int i,j,n,x;
	i=0;
	long long sol = 0;
	while(scanf("%c", &c) != -1) {
		if ( c == ',' ) {
			i = i + 1;
			j=0;

		} else {
			if ( c != '"') {
				names[i][j] = c;
				j++;
			}
		}
	}
	for(x=0;x<=i;x++) {
		n = strlen(names[x]);
		for(j=0; j<n; j++)
			printf("%c", names[x][j]);
		printf(" ");
	}
	printf("\n");
	mergeSort(0,i);
	for(x=0;x<=i;x++) {
		n = strlen(names[x]);
		for(j=0;j<n;j++) {
			printf("%c", names[x][j]);
			sol = sol + (names[x][j] - 64)*(x+1);
		}
		printf(" ");
	}
	printf("\n%lld\n", sol);
	return 0;
}
