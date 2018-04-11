#include<stdio.h>
int main()
{
	int com[1000];
	int sqrt[1000*1000];
	int i,a,b,c,mx,xx;
	mx=0;xx=0;
	for(i=0;i<1000*1000;i++)
		sqrt[i] = 0;
	for(i=1;i<1000;i++)
		sqrt[i*i] = i;
	for(i=0;i<1000;i++) {
		com[i] = 0;
	}
	for(a=1;a<500;a++) {
		for(b=a;b<500;b++) {
			c = sqrt[a*a+b*b];
			if (c != 0 && (a+b)>c) {
				//printf("%d, %d, %d %d\n", a, b, c, a+b+c);
				if(a+b+c <=1000)
					com[a+b+c-1]++;
			}
		}
	}
	for(i=12;i<1000;i++) {
		xx = (com[i] > mx)? (i+1) : xx;
		mx = (com[i] > mx)? com[i] : mx;
	}
	//printf("120:%d\n", com[119]);
	printf("%d:%d\n", xx, mx);
	return 0;
}
