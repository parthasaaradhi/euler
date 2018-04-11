#include<stdio.h>
int main()
{
	int month = 0;
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = 1900;
	int day = 1;
	int cnt = 0;
	int daysforward;
	while(year<2001) {
		daysforward = days[month];
		if (day == 0 && year != 1900)
			cnt++;
		if (month == 1) {
			if((year%4 == 0 && year%100 != 0) || year%400 == 0)
				daysforward = 29;
		}
		day = (day + daysforward)%7;
		if(month == 11) {
			month = 0;
			year++;
		} else {
			month++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

