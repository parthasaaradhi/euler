#include<stdio.h>

int num_a[200];
int num_b[200];
int num_t[400];

void multiply_a_b() {
	int i,j,k,carry;
	k=0;
	for(j=199;j>-1;j--) {
		carry = 0;
		for(i=199;i>-1;i--) {
			num_t[399-k+i-199] = num_a[i]*num_b[j] + carry + num_t[399-k+i-199];
			carry = num_t[399-k+i-199]/10;
			num_t[399-k+i-199] = num_t[399-k+i-199]%10;
		}
		i = 399-k-200;
		while(i>-1) {
			num_t[i] = num_t[i] + carry;
			carry = num_t[i]/10;
			num_t[i] = num_t[i]%10;
			i--;
		}
		k++;
	}
}

void clean_t() {
	int i;
	for(i=0;i<400;i++) {
		num_t[i] = 0;
	}
	return;
}

void fill_a(int n) {
	int i,carry;
	for(i=199;i>-1;i--)
		num_a[i] = 0;
	i = 199;
	while(n!=0) {
		num_a[i] = n%10;
		n = n/10;
		i--;
	}
	return;
}

void fill_b(int n) {
	int i,carry;
	for(i=199;i>-1;i--)
		num_b[i] = 0;
	i = 199;
	while(n!=0) {
		num_b[i] = n%10;
		n = n/10;
		i--;
	}
	return;
}
void print_t() {
	int i;
	i = 0;
	while(num_t[i] == 0 && i<400)
		i++;
	printf("Number: ");
	while(i<400) {
		printf("%d", num_t[i]);
		i++;
	}
	printf("\n");
	return;
}

int main() {
	clean_t();
	fill_a(985);
	fill_b(125);
	multiply_a_b();
	print_t();
	return 0;
}
