#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 105
int appx_sqrt(int n) {
	int i=0;
	while(i*i <= n) i++;
	return i-1;
}

void copy(int* src, int* dst) {
	int i;
	for(i=0;i<MAXSIZE;i++) dst[i] = src[i];
	return;
}

void setnum(int n, int* a) {
	int i;
	i=MAXSIZE-1;
	while(n!=0) {
		a[i] = n%10;
		n = n/10;
		i--;
	}
	return;
}

void mult(int n, int* a) {
	int i,c;
	c=0;
	for(i = MAXSIZE-1;i>-1;i--) {
		a[i] = a[i]*n+c;
		c = a[i]/10;
		a[i]=a[i]%10;
	}
	return;
}

void mult_product(int n, int *m, int* ans) {
	int i,c;
	c = 0;
	for(i=MAXSIZE-1;i>-1;i--) {
		ans[i] = m[i]*n+c;
		c = ans[i]/10;
		ans[i] = ans[i]%10;
	}
	return;
}

void plus(int n, int* number) {
	int i,c;
	i=MAXSIZE-1;
	c = n;
	do {
		number[i] = number[i] + c;
		c = number[i]/10;
		number[i] = number[i]%10;
	} while(c != 0);
	return ;
}

int less_or_equal(int* left, int* right) {
	int i;
	for(i=0;i<MAXSIZE;i++) {
		if(left[i] > right[i]) return 1;
		if(left[i] < right[i]) return 0;
	}
	return 0;
}

int find(int* a, int* reminder) {
	int x, *p, *z;
	p = malloc(sizeof(int)*MAXSIZE);
	mult_product(20, a, p);
	for(x=0;x<10;x++) {
		z = malloc(MAXSIZE*sizeof(int));
		copy(p, z);
		plus(x, z);
		mult(x, z);
		if(less_or_equal(z, reminder) == 1) {
			free(z);
			free(p);
			return x-1;
		}
		free(z);
	}
	free(p);
	return 9;
}

void subtract(int* from, int* sub) {
	int i,c;
	c = 0;
	for(i=MAXSIZE-1;i>-1;i--) {
		from[i] = from[i] - c - sub[i];
		if(from[i]<0) {
		       from[i] = from[i] + 10;
		       c = 1;
		} else c = 0;
	}
}

void handle_reminder(int* reminder, int* digits, int x) {
	int* p;
	p = malloc(MAXSIZE*sizeof(int));
	mult_product(20, digits, p);
	plus(x, p);
	mult(x, p);
	subtract(reminder, p);
	free(p);
	return;
}

int main() {
	int digits[MAXSIZE];
	int reminder[MAXSIZE];
	int n,i,x,c,j;
	int ans;
	ans = 0;
	for(n=2;n<100;n++) {
		x = appx_sqrt(n);
		if(x*x != n) {
			for(i=0;i<MAXSIZE;i++) {
				digits[i] = 0;
				reminder[i] = 0;
			}
			c = n - x*x;
			setnum(x, digits);
			setnum(c, reminder);
			for(j=0;j<99;j++) {
				mult(100, reminder);
				x = find(digits, reminder);
				handle_reminder(reminder, digits, x);
				mult(10, digits);
				plus(x, digits);
			}
			for(j=0;j<MAXSIZE;j++)
				ans = ans + digits[j];
		}

	}
	printf("%d\n", ans);
	return 0;
}
