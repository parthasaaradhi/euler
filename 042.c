#include<stdio.h>
#include<string.h>
int main()
{
	int t[70];
	char names[2000][50];
	int i,j,x,n; t[0] = 0;
	char c;long long s,p;
	for(i=1;i<70;i++)
		t[i] = t[i-1] + i;
	for(i=0;i<70;i++)
		printf("%d ", t[i]);
	i=0;
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
	s = 0;
	for(x=0;x<i;x++) {
		p = 0;
		n = strlen(names[x]);
		for(j=0;j<n;j++) {
			p = p + names[x][j] - 64;
		}
		for(j=0;j<70;j++)
			if(t[j] == p)
				s++;
				//printf("%s\n", names[x]);
	}
	printf("%lld\n", s);
	return 0;
}
