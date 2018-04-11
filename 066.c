#include<stdio.h>
int num_old[40];
int den_old[40];
int num_new[40];
int den_new[40];
int num_cop[40];
int den_cop[40];
int num_square[80];
int den_square[80];
int max_num[40];
int max_n;

void clean_num_den_new_old(int x) {
	int i;
	for(i=39;i>-1;i--) {
		num_new[i] = 0;
		num_old[i] = 0;
		den_new[i] = 0;
		den_old[i] = 0;
	}
	num_old[39] = 1;
	den_old[39] = 0;
	den_new[39] = 1;
	i=39;
	while(x!=0) {
		num_new[i] = x%10;
		x = x /10;
		i--;
	}
	return;
}

void clean_squares() {
	int i;
	for(i=79;i>-1;i--) {
		num_square[i] = 0;
		den_square[i] = 0;
	}
	return;
}

void num_den_copy() {
	int i;
	for(i=0;i<40;i++) {
		num_cop[i] = num_new[i];
		den_cop[i] = den_new[i];
	}
	return;
}

void copy_num_den() {
	int i;
	for(i=0;i<40;i++) {
		num_old[i] = num_cop[i];
		den_old[i] = den_cop[i];
	}
	return;
}

void iterate_num_den(int x) {
	int i,carry;
	carry = 0;
	for(i=39;i>-1;i--) {
		num_new[i] = num_new[i]*x + num_old[i] + carry;
		carry = num_new[i]/10;
		num_new[i] = num_new[i]%10;
	}
	carry = 0;
	for(i=39;i>-1;i--) {
		den_new[i] = den_new[i]*x + den_old[i] + carry;
		carry = den_new[i]/10;
		den_new[i] = den_new[i]%10;
	}
	return;
}

int check_diophantine(int n) {
	int i,j,k,carry;
	k=0;
	clean_squares();
	for(j=39;j>-1;j--) {
		carry=0;
		for(i=39;i>-1;i--) {
			num_square[79-k+i-39] = num_new[i]*num_new[j] + carry + num_square[79-k+i-39];
			carry = num_square[79-k+i-39]/10;
			num_square[79-k+i-39] = num_square[79-k+i-39]%10;
		}
		i=79-k-40;
		while(i>-1) {
			num_square[i] = num_square[i] + carry;
			carry = num_square[i]/10;
			num_square[i] = num_square[i]%10;
			i--;
		}
		k++;
	}
	k=0;
	for(j=39;j>-1;j--) {
		carry = 0;
		for(i=39;i>-1;i--) {
			den_square[79-k+i-39] = den_new[i]*den_new[j] + carry + den_square[79-k+i-39];
			carry = den_square[79-k+i-39]/10;
			den_square[79-k+i-39] = den_square[79-k+i-39]%10;
		}
		i=79-k-40;
		while(i>-1) {
			den_square[i] = den_square[i] + carry;
			carry = den_square[i]/10;
			den_square[i] = den_square[i]%10;
			i--;
		}
		k++;
	}
	carry = 1; // num*num == den*den*n+1 ?
	for(i=79;i>-1;i--) {
		den_square[i] = den_square[i] * n + carry;
		carry = den_square[i]/10;
		den_square[i] = den_square[i]%10;
	}
	for(i=79;i>-1;i--) {
		if(den_square[i] != num_square[i])
			return 1;
	}
	return 0;
}

void print_num_den() {
	int i;
	i = 0;
	while(num_new[i] == 0)
		i++;
	printf("\tNumerator: ");
	while(i<40) {
		printf("%d", num_new[i]);
		i++;
	}
	printf(" Denominator: ");
	i=0;
	while(den_new[i] == 0)
		i++;
	while(i<40) {
		printf("%d", den_new[i]);
		i++;
	}
	printf("\n");
	return;
}

void compare_max_and_update(int n) {
	int i,j;
	i=0;
	j=0;
	while(num_new[i] == 0)
		i++;
	while(max_num[j] == 0 && j<40)
		j++;
	if(j<i)
		return;
	else if (j>i) {
		for(i=0;i<40;i++)
			max_num[i] = num_new[i];
		max_n = n;
		return;
	} else {
		while(num_new[j] == max_num[j])
			j++;
		if(max_num[j] > num_new[j])
			return;
		else {
			for(i=0;i<40;i++)
				max_num[i] = num_new[i];
			max_n = n;
			return;
		}
	}
}

void print_max() {
	int i;
	i=0;
	printf("Max Num: ");
	while(max_num[i] == 0)
		i++;
	while(i<40) {
		printf("%d", max_num[i]);
		i++;
	}
	printf(" Max: %d\n", max_n);
	return;
}

int main()
{
	long long x,y,z,i,n,first,lulz;
	lulz = 2;
	for(i=0;i<40;i++)
		max_num[i] = 0;
	max_n = 2;
	for(n=2;n<=1000;n++) {
		if(lulz*lulz == n) {
			lulz++;
		} else {
			printf("%lld: "/*%lld; "*/, n/*, lulz-1*/);
			y = lulz-1;
			x = lulz-1;
			z = 1;
			first = 0;
			clean_num_den_new_old(x);
			while(/*(!(y == lulz-1 && z == 1) || first==0) && */(check_diophantine(n) != 0)) {
				first++;
				z = (n - y*y)/z;
				x = 1;
				while((z*x-y)*(z*x-y) < n)
					x++;
				x--;
				y=z*x-y;
				num_den_copy();
				iterate_num_den(x);
				copy_num_den();
				//printf("%d ", x);
			}
			compare_max_and_update(n);
			print_num_den();
		}
	}
	print_max();
	//printf("%d\n", total);
	return 0;
}

