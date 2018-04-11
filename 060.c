#include<stdio.h>
char seive[10000*10000];
char adj_mat[10000][10000];
int intersecion[10000];


int find_clique_size(int n, int p) {
	int i,j,found;
	found = 1;
	if(n==1) {
		printf("%d: %d\n", n, p);
		return 0;
	} else {

		for(i=p;i<10000;i++) {
			if(adj_mat[p][i] == '1' && intersecion[i] > -1) {
				for(j=0;j<10000;j++)
					if(adj_mat[i][j] == '0')
						intersecion[j] = intersecion[j] - 1;
				found = find_clique_size(n-1, i);
				if(found == 0) {
					printf("%d : %d\n", n, p);
					return 0;
				}
				for(j=0;j<10000;j++)
					if(adj_mat[i][j] == '0')
						intersecion[j] = intersecion[j] + 1;
			}
		}
		return 1;
	}
}


void mark_edge(int a, int b) {
	int x,y;
	x = 1;
	y = a;
	while(y!=0) {
		x = x*10;
		y = y/10;
	}
	if(x*b+a < 10000*10000 && seive[x*b+a] == '0') {
		y = b;
		x = 1;
		while(y!=0) {
			x = x*10;
			y = y/10;
		}
		if(x*a+b < 10000*10000 && seive[x*a+b] == '0') {
			adj_mat[a][b] = '1';
			adj_mat[b][a] = '1';
		}
	}
}

int main()
{
	int i,j,x;
	for(i=2;i<10000*10000;i++)
		seive[i] = '0';
	for(i=0;i<10000;i++)
		for(j=0;j<10000;j++)
			adj_mat[i][j] = '0';
	for(i=2;i<10000;i++)
		if (seive[i] == '0')
			for(j=i*i;j<10000*10000;j=j+i)
				seive[j] = '1';
	for(i=2;i<10000;i++)
		if(seive[i] == '0')
			for(j=i+1;j<10000;j++)
				if(seive[j] == '0')
					mark_edge(i, j);
	/*for(i=2;i<1000;i++)
		if(seive[i] == '0') {
			x = 0;
			for(j=2;j<1000;j++)
				x = x + adj_mat[i][j] - '0';
			printf("%d : %d\n", i, x);
		}*/
	for(j=3;j<10000;j++) {
		if(seive[j] == '0') {
			for(i=0;i<10000;i++)
				intersecion[i] = 0;
			for(i=0;i<10000;i++)
				if(adj_mat[j][i] == '0')
					intersecion[i]--;
			if (find_clique_size(5, j) == 0)
				return 0;
		}
	}
	return 0;
}
