#include<stdio.h>
char p[10][2];
//char order[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
int suits[8]; // C D H S C D H S
int occurs[13][2];

int map(char s)
{
	int pos;
	switch(s)
	{
		case 'T':
			pos = 8;
			break;
		case 'J':
			pos = 9;
			break;
		case 'Q':
			pos = 10;
			break;
		case 'K':
			pos = 11;
			break;
		case 'A':
			pos = 12;
			break;
		default:
			pos = s - '2';
			break;
	}
	return pos;
}

void clean()
{
	int i;
	for(i=0;i<13;i++) {
		occurs[i][0] = 0;
		occurs[i][1] = 0;
	}
	for(i=0;i<8;i++)
		suits[i] = 0;
	return;
}

void fill() 
{
	int i;
	for(i=0;i<5;i++)
	{
		occurs[map(p[i][0])][0]++;
		occurs[map(p[i+5][0])][1]++;
	}
	for(i=0;i<10;i++)
	{
		switch(p[i][1]) {
			case 'C':
				suits[(i/5)*4+0]++;
				break;
			case 'D':
				suits[(i/5)*4+1]++;
				break;
			case 'H':
				suits[(i/5)*4+2]++;
				break;
			case 'S':
				suits[(i/5)*4+3]++;
				break;
		}

	}
	return;
}

int highCard(int f) {
	int i;
	for(i=12;i>-1;i--)
		if(occurs[i][f] == 1)
			return i;
}

int secondPair(int f) {
	int i,x;
	x = pair(f);
	if (x<=0)
		return -1;
	for(i=x-1;i>-1;i--)
		if(occurs[i][f] == 2)
			return i;
	return -1;

}

int pair(int f) {
	int i;
	for(i=12;i>-1;i--)
		if(occurs[i][f] == 2)
			return i;
	return -1;
}

int threeOfKind(int f) {
	int i;
	for(i=12;i>-1;i--)
		if(occurs[i][f] == 3)
			return i;
	return -1;
}

int fullHouse(int f) {
	int t,p;
	t = threeOfKind(f);
	p = pair(f);
	if (t != -1 && p != -1)
		return t;
	return -1;
}

int fourOfKind(int f) {
	int i;
	for(i=12;i>-1;i--)
		if (occurs[i][f] == 4)
			return i;
	return -1;
}

int straight(int f) {
	int i,j,x;
	for(i=12;i>3;i--)
	{
		x = 0;
		for(j=0;j<5;j++)
			x = x + ((occurs[i-j][f] == 1)? 1 : 0);
		if(x==5)
			return i;
	}
	return -1;
}

int flush(int f) {
	int i;
	for(i=0;i<4;i++)
		if(suits[f*4+i] == 5)
			return 0;
	return -1;
}

int straightFlush(int f) {
	return ((flush(f)!=-1)? straight(f) : -1);
}

int royalFlush(int f) {
	int x;
	x = straightFlush(f);
	return ((x==12)? x : -1);
}

int main()
{
	int i,j,x,s;
	char c;
	int ans[2];
	s = 0;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<10;j++)
		{
			scanf("%c%c", &p[j][0], &p[j][1]);
			scanf("%c", &c);
		}
		for(j=0;j<10;j++) {
			printf("%c%c ", p[j][0], p[j][1]);
		}
		clean();
		fill();
		for(j=0;j<2;j++)
		{
			ans[j] = 0;
			if(royalFlush(j) != -1) {
				printf(" Found %d royal ", j);
				ans[j] = 10*13*13;
			}
			else if(straightFlush(j) != -1) {
				x = straightFlush(j);
				printf(" Found %d straight flush with %d", j, x);
				ans[j] = 9*13*13+x*13;
			}
			else {
				x = fourOfKind(j);
				if(x != -1) {
					printf(" Found %d four of kind with %d ", j, x);
					ans[j] = 8*13*13+x*13;
				}
				x = fullHouse(j);
				if(x != -1) {
					printf(" Found %d fullHouse with %d ", j, x);
					ans[j] = 7*13*13+x*13+pair(j);
				} else {
					x = threeOfKind(j);
					if(x != -1) {
						printf(" Found %d three of a kind with %d", j, x);
						ans[j] = 4*13*13+x*13;
					}
					x = secondPair(j);
					if(x != -1) {
						printf(" Found %d 2 pairs of %d %d ", j, x, pair(j));
						ans[j] = 3*13*13+x*13+pair(j);
					} else {
						x = pair(j);
						if(x != -1) {
							printf(" Found %d pair of %d ", j, x);
							ans[j] = 2*13*13+x*13;
						}
					}
				}
				x = flush(j);
				if(x != -1) {
					printf(" Found %d flush with %d ", j, x);
					ans[j] = 6*13*13+highCard(j)*13;
				}
				x = straight(j); 
				if(x != -1) {
					printf(" Found %d straight with %d ", j, x);
					ans[j] = 5*13*13+x*13;
				}
				if(ans[j] == 0)
					ans[j] = 1*13*13+highCard(j)*13;

			}
		}
		for(j=0;j<2;j++)
			printf(" Ans %d:%d\t", j, ans[j]);
		if(ans[0] > ans[1])
			s++;
		if (ans[0] == ans[1]) {
			if(highCard(0) > highCard(1)) {
				s++;
				printf(" 0 LUL ");
			}
			else
				printf(" 1 LUL ");
		}
		printf("\n");
	}
	printf("Final Answer: %d\n", s);
	return 0;
}
