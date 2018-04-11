#include<stdio.h>
int main()
{
	int i,j,x; char c;
	char key[3];
	key[0] = 'g';
	key[1] = 'o';
	key[2] = 'd';
	int encrypt[1250];
	int count[26][3];
	scanf("%d", &encrypt[0]);
	i = 0;
	while(scanf("%c", &c) != -1) {
		i++;
		scanf("%d", &encrypt[i]);
	}

	for(j=0;j<26;j++) {
		count[j][0] = 0;
		count[j][1] = 0;
		count[j][2] = 0;
	}

	for(j=0;j<i;j++) {
			for(x=97;x<123;x++) {
				c = encrypt[j]^x;
				if(c < 32 || c > 126)
					count[x-97][j%3]++;
				//printf("%c", c);
			}
			//printf("\n");
	}
	printf("\n");
	for(j=0;j<i;j++) {
		//printf("%d::", j);
		if (j%3 == 0) {
			c = encrypt[j]^(6+97);
			printf("%c", c);
		} else if(j%3 == 1) {
			c = encrypt[j]^(14+97);
			printf("%c", c);
		} else {
			//for(x=0;x<26;x++) {
			//	if (count[x][j%3] == 0) {
					c = encrypt[j]^(3+97);
					printf("%c", c);
			//	}
			//}
		}
	}
	printf("\n");
	x = 0;
	for(j=0;j<i;j++)
		x = x + (encrypt[j]^key[j%3]);
	printf("%d\n", x);
	return 0;
}
