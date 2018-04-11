#include<stdio.h>
#include<string.h>
int main()
{
	long long tens,twentys,hundreds;
	int i;
	long long s=0;
	tens = twentys = hundreds = 0;
	char ten_str[9][10] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char ele_str[9][10] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char tty_str[9][10] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", ""};
	for(i=0;i<9;i++) {
		tens = tens + strlen(ten_str[i]);
		twentys = twentys + strlen(ele_str[i]);
		hundreds = hundreds + strlen(tty_str[i]);
	}
	s = tens + strlen("ten") + twentys + hundreds * 10 + 8 * tens; // One to ninety nine.
	s = strlen("hundred") * 900 + strlen("and") * 99 * 9 + tens * 100 + s * 10; // One hundred to nine hundred and ninety nine;
	s = s + strlen("one") + strlen("thousand"); // One thousand
	printf("%lld\n", s);
	return 0;
}
