#include<stdio.h>
int digits[201];
char strs[9801][201];
char temps[9801][201];
int cnt;
int compare(int x, int y) {
	int i=200;
	while(i != -1 && strs[x][i] == strs[y][i])
		i--;
	if(i == -1)
		return x;
	else
		return (strs[x][i] > strs[y][i]) ? y : x;
}
void mergeSort(int in, int fi) {
	int v;
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
		for(v=0;v<201;v++)
			temps[x][v] = strs[len][v];
		x++;
		if (len == j)
			j++;
		else
			i++;
	}
	for(i=in;i<=fi;i++)
		for(v=0;v<201;v++)
			strs[i][v] = temps[i][v];
	return;

}
void pow_from_2_to_100(int n) {
	int i,j,carry;
	digits[0] = 1;
	for(i=1;i<201;i++)
		digits[i] = 0;
	for(i=1;i<=100;i++) {
		carry = 0;
		for(j=0;j<201;j++) {
			digits[j] = digits[j] * n + carry;
			carry = digits[j]/10;
			digits[j] = digits[j]%10;
		}
		if(i>1)
		{
			for(j=200;j>-1;j--)
				strs[cnt][j] = 48+digits[j];
			cnt++;
		}
	}
}

int main() {
	int i,j;
	int y;
	int s;
	cnt = 0;
	for(i=2;i<101;i++)
		pow_from_2_to_100(i);
	mergeSort(0,9800);
	for(j=200;j>-1;j--)
		temps[0][j] = strs[0][j];
	s = 1;
	for(i=1;i<cnt;i++) {
		y = 0;
		for(j=200;j>-1;j--) {
			if (strs[i][j] != temps[0][j]) {
				y = 1;
			}
			temps[0][j] = strs[i][j];
		}
		s = s + y;
	}
	printf("%d\n", s);
	return 0;
}
