#include<stdio.h>

int sign(int x)
{
	if(x==0)
		return 0;
	if(x<0)
		return -1;
	if(x>0)
		return 1;
}

int substitute(int a, int b, int x1, int y1, int x2, int y2)
{
	return sign((y2-y1)*a - (x2-x1)*b + x2*y1 - x1*y2);
}

int are_same_side(int a, int b, int x1, int y1, int x2, int y2)
{
	return substitute(a,b,x1,y1,x2,y2)*substitute(0,0,x1,y1,x2,y2);
}

int main()
{
	int i;
	int x[3],y[3];
	int p,a,b,c,sum;
	sum=0;
	for(i=0;i<1000;i++)
	{
		scanf("%d %d %d %d %d %d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
		a = are_same_side(x[2], y[2], x[0], y[0], x[1], y[1]);
		b = are_same_side(x[0], y[0], x[1], y[1], x[2], y[2]);
		c = are_same_side(x[1], y[1], x[2], y[2], x[0], y[0]);

		if(a+b+c == 3)
			sum++;
	}
	printf("%d\n", sum);
	return 0;
}
