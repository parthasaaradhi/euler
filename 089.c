#include<stdio.h>

int value(char c) {
	if(c == 'M') return 1000;
	if(c == 'D') return 500;
	if(c == 'C') return 100;
	if(c == 'L') return 50;
	if(c == 'X') return 10;
	if(c == 'V') return 5;
	if(c == 'I') return 1;
	return 0;
}

int convert_back(int n) {
	int x;
	x = 0;
	while(n>=1000) {
		/*printf("M");*/n = n - 1000;x++;
	}
	if(n>=900) {
		/*printf("CM");*/n = n - 900;x=x+2;
	}
	if(n>=500) {
		/*printf("D");*/n = n - 500;x++;
	}
	if(n>=400) {
		/*printf("CD");*/n=n-400;x=x+2;
	}
	while(n>=100) {
		/*printf("C");*/n = n-100;x++;
	}
	if(n>=90) {
		/*printf("XC");*/n = n-90;x=x+2;
	}
	if(n>=50) {
		/*printf("L");*/n=n-50;x++;
	}
	if(n>=40) {
		/*printf("XL");*/n=n-40;x=x+2;
	}
	while(n>=10) {
		/*printf("X");*/n=n-10;x++;
	}
	if(n==9) {
		/*printf("IX");*/n=n-9;x=x+2;
	}
	while(n>=5) {
		/*printf("V");*/n=n-5;x++;
	}
	if(n==4) {
		/*printf("IV");*/n=n-4;x=x+2;
	}
	while(n>0) {
		/*printf("I");*/n--;x++;
	}
	return x;
}

int main() {
	int i,n,x,d,ans;char c,prev;
	ans=0;
	for(i=0;i<1000;i++) {
		prev = '\n';
		n=0;d=-1;
		do {
			scanf("%c", &c);
			d++;
			if(c=='M' && prev=='C')
				n=n+900-100;
			else if(c=='D' && prev=='C')
				n=n+400-100;
			else if(c=='C' && prev=='X')
				n=n+90-10;
			else if(c=='L' && prev=='X')
				n=n+40-10;
			else if(c=='X' && prev=='I')
				n=n+9-1;
			else if(c=='V' && prev=='I')
				n=n+4-1;
			else {
				n = n + value(c);
			}
			prev = c;
		} while(c!='\n');
		x = convert_back(n);
		ans = ans + d-x;
		//printf(" %d\n", d-x);
	}
	printf("%d\n", ans);
	return 0;
}
