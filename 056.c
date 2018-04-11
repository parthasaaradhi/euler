#include<stdio.h>
long long num[205];

long long clean_fill_initial_digit_sum(long long a) {
	long long s;int i;
	for(i=0;i<205;i++)
		num[i] = 0;
	i=204;
	while(a!=0) {
		num[i] = a%10;
		a = a/10;
		i--;
	}
	s=0;
	for(i=0;i<205;i++)
		s = s+num[i];
	return s;
}

long long power_up_digit_sum(long long a) {
	long long c; int i;
	c = 0;
	for(i=204;i>-1;i--) {
		num[i] = num[i]*a + c;
		c = num[i]/10;
		num[i] = num[i]%10;
	}
	c = 0;
	for(i=0;i<205;i++)
		c = c + num[i];
	return c;
}

void print_num() {
	int i;
	i=0;
	while(num[i]==0)
		i++;
	while(i<205) {
		printf("%lld", num[i]);
		i++;
	}
	printf("\n");
	return;
}

int main()
{
	long long a,b,s,max_sum;
	s=0; max_sum=0;
	for(a=1;a<100;a++) {
		s = clean_fill_initial_digit_sum(a);
		max_sum = (s>max_sum)? s : max_sum;
		for(b=2;b<100;b++) {
			s = power_up_digit_sum(a);
			print_num();
			max_sum = (s>max_sum)? s : max_sum;
		}
	}
	printf("%lld\n", max_sum);
	return 0;
}
