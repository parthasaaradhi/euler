#include<stdio.h>
int num[200];
int den[200];
int temp[200];

void num_copy() {
	int i;
	for(i=0;i<200;i++)
		temp[i] = num[i];
}

void copy_den() {
	int i;
	for(i=0;i<200;i++)
		den[i] = temp[i];
}

void num_multiply_q(int q) {
	int i,carry;
	carry = 0;
	for(i=199;i>-1;i--) {
		num[i] = num[i]*q+carry;
		carry = num[i]/10;
		num[i] = num[i]%10;
	}
}

void num_add_den() {
	int i,carry;
	carry = 0;
	for(i=199;i>-1;i--) {
		num[i] = num[i] + den[i] + carry;
		carry = num[i]/10;
		num[i] = num[i]%10;
	}
}

void set_num_den(int n, int d) {
	int i;
	for(i=0;i<200;i++) {
		num[i] = 0;
		den[i] = 0;
	}
	i=199;
	while(n!=0) {
		num[i] = n%10;
		n=n/10;
		i--;
	}
	i=199;
	while(d!=0) {
		den[i] = d%10;
		d=d/10;
		i--;
	}
}

void print_num_den() {
	int i;
	i=0;
	while(num[i]==0)
		i++;
	printf("Num: ");
	while(i<200) {
		printf("%d", num[i]);
		i++;
	}
	printf("\t");
	printf("Den: ");
	i=0;
	while(den[i]==0)
		i++;
	while(i<200) {
		printf("%d", den[i]);
		i++;
	}
	printf("\n");
	return;
}

int main()
{
	int i,q;
	set_num_den(1, 0);
	for(i=99;i>0;i--) {
		if(i%3==2)
			q = 2*(i+1)/3;
		else
			q = 1;
		num_copy();
		num_multiply_q(q);
		num_add_den();
		copy_den();
		print_num_den();
	}
	num_copy();
	num_multiply_q(2);
	num_add_den();
	copy_den();
	print_num_den();
	q = 0;
	for(i=0;i<200;i++)
		q=q+num[i];
	printf("%d\n", q);
	return 0;
}
