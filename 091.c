#include<stdio.h>

int distsq(int x1, int y1, int x2, int y2)
{
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int checkPyth(int x, int y, int z)
{
	return ((x+y==z) || (y+z==x) || (z+x==y));
}

int main()
{
	int x1,x2,y1,y2;
	int n=50;
	int t=0;
	for(x1=0;x1<=n;x1++)
	{
		for(x2=0;x2<=n;x2++)
		{
			for(y1=0;y1<=n;y1++)
			{
				for(y2=0;y2<=n;y2++)
				{
					if(! ((x1==x2 && y1==y2) || (x1==0 && y1==0) || (x2==0&& y2==0)))
					{
						if(checkPyth(
									distsq(0,0,x1,y1),
									distsq(0,0,x2,y2),
									distsq(x1,y1,x2,y2)
									))
						{
							t++;
							//printf("%d,%d : %d,%d\n", x1,y1, x2, y2);
						}
					}
				}
			}
		}
	}
	printf("Final: %d\n", t/2);
	return 0;
}
