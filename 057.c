#include<stdio.h>
int num_x[400];
int num_y[400];

void fill_x_y(long long x, long long y) {
	int i;
	for(i=0;i<400;i++) {
		num_x[i] = 0;
		num_y[i] = 0;
	}
	i = 399;
	while(x!=0) {
		num_x[i] = x%10;
		x = x/10;
		i--;
	}
	i=399;
	while(y!=0) {
		num_y[i] = y%10;
		y = y/10;
		i--;
	}
	return;
}

void iterate() {
	int i;
	int carry;
	carry = 0;
	for(i=399;i>=0;i--) {
		num_x[i] = 2 * num_y[i] + num_x[i] + carry;
		carry = num_x[i]/10;
		num_x[i] = num_x[i]%10;
	}
	carry = 0;
	for(i=399;i>=0;i--) {
		num_y[i] = num_x[i] - num_y[i] - carry;
		if (num_y[i] < 0) {
			num_y[i] = num_y[i] + 10;
			carry = 1;
		} else {
			carry = 0;
		}
	}
	return;
}

void print_x_y() {
	int i;
	i=0;
	while(num_x[i]==0)
		i++;
	//printf("x: ");
	while(i<400) {
		printf("%d", num_x[i]);
		i++;
	}
	printf(" ");
	i=0;
	while(num_y[i]==0)
		i++;
	//printf("y: ");
	while(i<400) {
		printf("%d", num_y[i]);
		i++;
	}
	printf("\n");
	return;
}

int num_den() {
	int i,j;
	i=0;j=0;
	while(num_x[i]==0)
		i++;
	while(num_y[j]==0)
		j++;
	return (i < j)? 1 : 0;
}
	
int main()
{
	int i,s;
	fill_x_y(3, 2);
	s = 0;
	for(i=1;i<1000;i++) {
		iterate();
		s = s + num_den();
		//print_x_y();
	}
	printf("%d\n", s);
	return 0;
}
