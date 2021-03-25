#include<stdio.h>
int main()
{
	// 1 Jan 1900 -- Monday  s = 1;
	int len[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i;
	int s = 1;
	int year = 1900;
	int ans = 0;

	while(year < 2001)
	{
		if((year%4 == 0 && year%100 !=0) || (year%400==0))
			len[1] = 29;

		if(s==0 && year!=1900)
			ans++;

		for(i=0;i<11;i++)
		{
			s = (s + len[i])%7;
			if(s == 0 && year!=1900)
				ans++;
		}
		s = (s+len[11])%7;
		year++;
		len[1] = 28;
	}

	printf("%d\n", ans);
	return 0;
}
