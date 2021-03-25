#include<stdio.h>
int is_palindrome(int n)
{
	int x,y;
	x=0;
	y=n;
	while(y!=0){
		x=10*x+y%10;
		y=y/10;
	}
	if(x==n)
		return 0;//true
	else
		return 1;//false

}

int main()
{
	int i,j,max;
	max = 0;
	for(i=100;i<1000;i++)
		for(j=i;j<1000;j++)
			if(is_palindrome(i*j) == 0)
				if(i*j>max)
					max=i*j;
	printf("%d\n", max);
	return 0;
}
