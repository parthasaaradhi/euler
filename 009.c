#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=3;a<333;a++)
		for(b=a+1;b<500;b++)
		{
			c=1000-a-b;
			if(c*c == a*a + b*b)
			{
				printf("%d\n", a*b*c);
				return 0;
			}
		}
	return 0;
}
