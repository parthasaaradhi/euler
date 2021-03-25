#include<stdio.h>

char words[1786][25];
int len[1786];
int alphabet[26];
char taken[10];

long long answer;

void store_highest(long long x, long long y)
{
	answer = x > answer ? x : answer;
	answer = y > answer ? y : answer;
}

int is_perfect_square(long long n)
{
	long long a;
	a = n;
	while(a*a>=n)
	{
		if(a*a == n)
			return 0;
		else
			a = (a+n/a)/2;
	}
	return 1;
}

int check_index_zero(int y)
{
	return alphabet[words[y][0] - 'A'] == 0 ? 0 : 1;
}

long long compute_values(int x)
{
	int i;
	long long v;
	v=0;
	for(i=0;i<len[x];i++)
		v = 10*v + alphabet[words[x][i] - 'A'];
	return v;
}

void print_char_values(int x)
{
	int i;
	printf("Assigned: ");
	for(i=0;i<len[x];i++)
		printf("%c", words[x][i]);
	printf(" Value: ");
	for(i=0;i<len[x];i++)
	{
		printf("%d", alphabet[words[x][i] - 'A']);
	}
	printf("\n");
	return;
}

void assign(int x,int y, int ind)
{
	int i;
	long long x_value;
	long long y_value;	
	if(ind == len[x])
	{
		x_value = compute_values(x);
		y_value = compute_values(y);

		if (check_index_zero(y) == 1 && is_perfect_square(x_value) == 0 && is_perfect_square(y_value) == 0)
			store_highest(x_value, y_value);
			//printf("Found %d %d %lld %lld\n", x, y, x_value, y_value);
		//print_char_values(x);
		return;
	}

	for(i=0;i<10;i++)
	{
		if(taken[i] == '\n')
		{
			while(alphabet[words[x][ind] - 'A'] != -1 && ind < len[x])
			{
				ind++;
			}
			if(ind >= len[x])
			{
				x_value = compute_values(x);
				y_value = compute_values(y);

				if (check_index_zero(y) == 1 && is_perfect_square(x_value) == 0 && is_perfect_square(y_value) == 0)
					store_highest(x_value, y_value);
					//printf("Found %d %d %lld %lld\n", x, y, x_value, y_value);
				//printf("Assigned %d\n", compute_values(x));
				//print_char_values(x);
				return;
			}
			if(!(ind == 0 && i == 0))
			{
				taken[i] = words[x][ind];
				alphabet[words[x][ind] - 'A'] = i;
				//printf(" lol %d %d", ind, i);
				assign(x, y, ind+1);
				alphabet[words[x][ind] - 'A'] = -1;
				taken[i] = '\n';
			}
		}
	}
}

void set_taken(char c)
{
	int i;
	for(i=0;i<10;i++)
		taken[i] = c;
}

void set_alphabet(int x)
{
	int i;
	for(i=0;i<26;i++)
		alphabet[i] = x;
}

int check_anagram(int x, int y)
{
	int i;
	if(len[x] != len[y])
		return 0;

	set_alphabet(0);

	for(i=0;i<len[x];i++)
	{
		alphabet[words[x][i] - 'A']++;
		alphabet[words[y][i] - 'A']--;

	}
	for(i=0;i<26;i++)
		if(alphabet[i]!=0)
			return 0;
	return 1;
}

int main()
{
	int i,j;
	char c;
	answer = 0;
	for(i=0;i<1786;i++)
	{
		len[i]=0;
		j=0;
		scanf("%c", &c);
		while(c!='\n')
		{
			len[i]++;
			words[i][j] = c;
			j++;
			scanf("%c", &c);
		}
		words[i][j] = '\n';
		/*for(j=0;j<len[i];j++)
		  printf("%c", words[i][j]);
		  printf(" :%d", len[i]);
		  printf("\n");*/
	}
	for(i=0;i<1786;i++)
	{
		for(j=i+1;j<1786;j++)
		{
			if(len[i] == len[j])
			{
				if(check_anagram(i,j) == 1)
				{
					//printf("Found anagram\n");
					set_alphabet(-1);
					set_taken('\n');
					assign(i , j, 0);
					//return 0;
					set_alphabet(-1);
					set_taken('\n');
				}
			}
		}
	}
	printf("%lld\n", answer);
	return 0;
}
