#include<stdio.h>
char mark[10000];
int stv;

int square_root(int n) {
	int x;
	x = n;
	while(!(n==x*x || ((n>x*x) && (n<(x+1)*(x+1))))) {
		x = (x + (n/x))/2;
	}
	return (x*x == n)? x : 0;
}

int octogonal(int n) {
	int x;
	x = square_root(1+3*n);
	if(x == 0)
		return 0;
	return ((x+1)%3 != 0)? 0 : 1;//(x+1)/3;
}

int heptagonal(int n) {
	int x;
	x = square_root(9+40*n);
	if(x == 0)
		return 0;
	return ((x+3)%10 != 0)? 0 : 1;//(x+3)/10;
}

int hexagonal(int n) {
	int x;
	x = square_root(1+8*n);
	if(x == 0)
		return 0;
	return ((x+1)%4 != 0)? 0 : 1;//(x+1)/4;
}

int pentatgonal(int n) {
	int x;
	x = square_root(1+24*n);
	if(x==0)
		return 0;
	return ((x+1)%6 != 0)? 0 : 1;//(x+1)/6;
}

int triangle(int n) {
	int x;
	x = square_root(1+8*n);
	if(x==0)
		return 0;
	return ((x-1)%2 != 0)? 0 : 1;//(x-1)/2;
}

int find_atleast_one(int x) {
	int y=0;
	y = y + 3*triangle(x);
	//y = y + ((square_root(x) != 0)? 1: 0);
	y = y + 5*pentatgonal(x);
	y = y + 6*hexagonal(x) - 3*triangle(x)*hexagonal(x);
	y = y + 7*heptagonal(x);
	y = y + 8*octogonal(x);
	if(y>0)
		return y;
	return 0;
}

int check_tail(int head, int tail) {
	return ((tail/100 == head%100) && tail!=head)? 0 : 1;
}

void find_cycles(int size, int sv) {
	int i,x,y;
	int lulz[9];
	if(size == 1) {
		x = check_tail(sv, stv);
		if(x == 0) {
			x=0;
			for(i=0;i<9;i++)
				lulz[i] = 0;
			//printf("Success:\t");
			for(i=1000;i<10000;i++) {
				if(mark[i] == '1') {
					y = find_atleast_one(i);
					lulz[y]++;
					x = x + i;
					//printf("%d: %d  ", i, y);
				}
			}
			//printf("\n");
			if(lulz[3]+lulz[6] == 2 && lulz[5] == 1 && lulz[7] == 1 && lulz[8] == 1)
				printf("%d^^^^lol^^^\n", x);
		}
		return;
	}
	x = sv%100;
	if(x>9) {
		for(i=0;i<99;i++) {
			if(mark[x*100+i] == '0') {
				mark[x*100+i] = '1';
				if(find_atleast_one(x*100+i) != 0) {
					find_cycles(size-1, x*100+i);
				}
				mark[x*100+i] = '0';
			}
		}
	}
}

int main()
{
	int i,j,x;
	for(i=0;i<10000;i++)
		mark[i] = '0';
	for(i=32;i<99;i++) {
		mark[i*i] = '1';
		stv = i*i;
		find_cycles(6, i*i);
		mark[i*i] = '0';
	}
	return 0;
}
