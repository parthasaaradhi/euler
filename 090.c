#include<stdio.h>
struct number {int first;int second;};
struct number sq[9];
int pf[10];int sf[10];
int check() {
	int i,cnt;cnt=0;
	for(i=0;i<9;i++) {
		if(
				(
				 (pf[sq[i].first]==1
				  || (sq[i].first==6 && pf[9]==1)
				  || (sq[i].first==9 && pf[6]==1)
				 )
				 &&
				 (sf[sq[i].second]==1
				  || (sq[i].second==6 && sf[9]==1)
				  || (sq[i].second==9 && sf[6]==1)
				 )
				)
				||
				(
				 (sf[sq[i].first]==1 
				  || (sq[i].first==6 && sf[9]==1)
				  || (sq[i].first==9 && sf[6]==1)
				 )
				 &&
				 (pf[sq[i].second]==1
				  || (sq[i].second==6 && pf[9]==1)
				  || (sq[i].second==9 && pf[6]==1)
				 )
				)
					)
					cnt++;
	}
	if(cnt==9) {
		/*
		for(i=0;i<10;i++)
			if(pf[i]==1)
				printf("%d", i);
		printf("\n");
		for(i=0;i<10;i++)
			if(sf[i]==1)
				printf("%d", i);
		printf("\n\n");
		*/
		return 1;
	} else
		return 0;
}
int choose_all(int i, int j, int p, int s) {
	int x=0;
	if(i+p>10)
		return 0;
	if(j+s>10)
		return 0;
	if(p==0 && s==0) {
		return check();
	}
	if(p>0 && s>0) {
		pf[i] = 1;sf[j] = 1;
		x = x + choose_all(i+1, j+1, p-1,s-1);
		pf[i] = 0; sf[j] = 0;
	}
	if(s>0) {
		sf[j] = 1;
		x = x + choose_all(i+1, j+1, p,s-1);
		sf[j] = 0;
	}
	if(p>0) {
		pf[i] = 1;
		x = x + choose_all(i+1, j+1, p-1,s);
		pf[i] = 0;
	}
	x = x + choose_all(i+1, j+1, p, s);
	return x;
}
int main() {
	int i;int pf[10],sf[10];
	for(i=0;i<9;i++) {
		sq[i].first = (i+1)*(i+1)/10;
		sq[i].second = ((i+1)*(i+1))%10;
	}
	for(i=0;i<10;i++)
		pf[i] = sf[i] = 0;
	/*for(i=0;i<9;i++)
		printf("%d%d ", sq[i].first, sq[i].second);
	printf("\n");*/
	printf("%d\n", choose_all(0,0,6,6)/2); // Dices are intechangable.
	return 0;
}
