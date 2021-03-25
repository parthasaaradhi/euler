#include<stdio.h>
int main()
{
	char** words;
	int i,j;
	char c;
	i = 0;
	scanf("%c", &c);
	while(c != '\n')
	{
		words = realloc((i+1)*sizeof(char *));
		words[i][j] = c;
		scanf("%c", &c);
		j++;
	}
	return 0;
}
