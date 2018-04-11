#include<stdio.h>
int digits[9];
int s[30];
int temps[30];

int compare(int l, int r) {
	return (s[l] > s[r])? r : l;
}

void mergeSort(int in, int fi) {
	if (in == fi)
		return;
	int len, ltend, i, j, x;
	len = fi + 1 - in;
	ltend = (len%2 == 0) ? (in + len/2 - 1) : (in + (len-1)/2);
	mergeSort(in, ltend);
	mergeSort(ltend+1, fi);
	i = in; j = ltend+1; x = in;
	while(x<=fi) {
		len = (i>ltend)? j : ((j>fi)? i : compare(i,j));
		temps[x] = s[len];
		x++;
		if(len == j)
			j++;
		else
			i++;
	}
	for(i=in;i<=fi;i++)
		s[i] = temps[i];
	return;
}

int distinctSum() {
	mergeSort(0,29);
	int sum,x,i;
	x=s[0];
	sum=x;
	for(i=1;i<30;i++) {
		if(x != s[i]) {
			x = s[i];
			sum = sum + x;
		}
	}
	return sum;
}

int validate(int m, int n) {
	int i;
	for(i=0;i<9;i++)
		digits[i] = 0;
	i = m;
	while(i!=0) {
		if(i%10 == 0)
			return 1;
		digits[i%10-1]++;
		i = i/10;
	}
	i = n;
	while(i!=0) {
		if(i%10 == 0)
			return 1;
		digits[i%10-1]++;
		i = i/10;
	}
	i = m*n;
	while(i!=0) {
		if(i%10 == 0)
			return 1;
		digits[i%10-1]++;
		i = i/10;
	}
	for(i=0;i<9;i++)
		if( digits[i] != 1)
			return 1;
	printf("%d, %d, %d\n", m, n, m*n);
	return 0;
}

int main()
{
	int m,n,i;
	for(i=0;i<30;i++)
		s[i] = 0;
	i=0;
	for(m=1;m<99;m++) {
		for(n=100;n<3000;n++)
			if (validate(m,n) == 0)
			{
				s[i] = m*n;
				i++;
			}
	}
	printf("Sum %d\n", distinctSum());
	for(i=0;i<30;i++)
		printf("%d ", s[i]);
	return 0;
}
