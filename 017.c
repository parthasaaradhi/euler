#include<stdio.h>
int main()
{
	int nu[10] = {3,3,5,4,4,3,5,5,4,3};
	int el[9] = {6,6,8,8,7,7,9,8,8};
	int tenty[8] = {6,6,5,5,5,7,6,6};
	int h = 7;
	int and = 3;
	int th = 8;

	int one_99;
	int i,j,x;
	one_99 = 0;
	x=0;

	// 1 - 10
	for(i=0;i<10;i++)
		one_99 = one_99 + nu[i];
	// 11 - 19
	for(i=0;i<9;i++)
		one_99 = one_99 + el[i];

	// 20 - 99
	for(j=0;j<8;j++)
	{
		// 20 - 29
		one_99 = one_99 + tenty[j];
		for(i=0;i<9;i++)
			one_99 = one_99 + tenty[j] + nu[i];
	}

	x = one_99;

	for(j=0;j<9;j++)
	{

		// 100 - 199
		x = x + nu[j] + h;
		x = x + 99*(nu[j]+h+and) + one_99;
	}

	x = x  + nu[0] + th;

	printf("%d\n", x);

	/*
	   char numbers[][] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
	   "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
	   "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "and"};*/

	return 0;
}
