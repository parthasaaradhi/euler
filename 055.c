#include<stdio.h>
int num_one[100];
int num_two[100];
int num_sum[100];

void fill_one_clean_two(int n)
{
	int i;
	for(i=99;i>-1;i--) {
		num_one[i] = n%10;
		n = n / 10;
	}
	for(i=0;i<100;i++) {
		num_two[i] = 0;
		num_sum[i] = 0;
	}
}

void add_one_two()
{
	int c,i;
	c = 0;
	for(i=0;i<100;i++)
		num_sum[i] = 0;
	for(i=99;i>=0;i--) {
		num_sum[i] = num_one[i] + num_two[i] + c;
		c = num_sum[i]/10;
		num_sum[i] = num_sum[i]%10;
	}
}

void reverse_one_two()
{
	int i,j;
	i=0;
	while(num_one[i]==0) {
		num_two[i] = 0;
		i++;
	}
	for(j=i;j<100;j++) {
		num_two[99-j+i] = num_one[j];
	}
}

int is_one_two_equal()
{
	int i;
	for(i=0;i<100;i++)
		if(num_one[i] != num_two[i])
			return 1;
	return 0;
}

void sum_one()
{
	int i;
	for(i=0;i<100;i++)
		num_one[i] = num_sum[i];
}

void print_sum()
{
	int i;
	i=0;
	while(num_sum[i]==0)
		i++;
	while(i<100) {
		printf("%d", num_sum[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int n,i,s;
	n = 1;s=9999;
	while(n<10000)
	{
		fill_one_clean_two(n);
		reverse_one_two();
		add_one_two();
		sum_one();
		for(i=1;i<50;i++) {
			reverse_one_two();
			if (is_one_two_equal() == 0) {
				print_sum();
				s--;
				break;
			}
			add_one_two();
			sum_one();
		}
		n++;
	}
	printf("%d\n", s);
	return 0;
}
