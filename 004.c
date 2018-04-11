#include<stdio.h>
int mypalindrome(int num)
{
	int x = 0;
	int n = num;
	while(n != 0) {
		x = 10*x + n%10;
		n = n/10;
	}
	return num == x;
}
int main()
{
	int x = 100;
	int y = 100;
	int ans = 0;
	int l = 0;
	for(x = 100; x < 1000; x++)
	{
		for(y = x ; y < 1000; y++)
		{
			l = x*y;
			if (mypalindrome(l) && ans < l)
			{
				ans = l;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
