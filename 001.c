#include<stdio.h>

int lol(int n) {
	return (n*(n+1))/2;
}
int main()
{
	printf("%d\n", 3 * lol(1000/3) + 5 * lol(199) - 15 * lol(1000/15));
	return 0;
}
