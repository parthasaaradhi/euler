#include<stdio.h>
int main()
{
	int a[20][20];
	char c;
	int i,j,x;
	int ans=0;;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			scanf("%c", &c);
			if(c!='0' && c!='1' && c!='2' && c!='3' && c!='4' && c!='5'
					&& c!='6' && c!='7' && c!= '8' && c!= '9')
				j--;
			else{
				x = c - '0';
				scanf("%c", &c);
				a[i][j] = 10*x + c -'0';
			}
		}
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			//right
			if(j+3<20)
			{
				x = a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
				if(x>ans)
					ans = x;
			}
			//down
			if(i+3<20)
			{
				x = a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
				if(x>ans)
					ans = x;
			}
			// diag--down
			if(i+3<20 && j+3<20)
			{
				x = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
				if(x>ans)
					ans = x;
			}
			//diag--up
			if(i+3<20 && j-3>0)
			{
				x = a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
				if(x>ans)
					ans = x;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
