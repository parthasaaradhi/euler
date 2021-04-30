#include<stdlib.h>
#ifndef NUMBER_H
#define NUMBER_H

#define MAX_DIGITS 1000

struct number {
	char sign;
	char digits[MAX_DIGITS];
};

void negate_number(struct number* n)
{
	n->sign = (n->sign == '+')? '-' : '+';
}

void number_print(struct number* ans)
{
	int i;
	//printf("Printing Number: %c", ans->sign);
	printf("%c", ans->sign);
	i=0;
	while(ans->digits[i] == '0' && i!=MAX_DIGITS)
		i++;
	if(i==MAX_DIGITS)
		printf("0");
	else
		while(i!=MAX_DIGITS)
		{
			printf("%c", ans->digits[i]);
			i++;
		}
	//printf("\n");
}

char get_sign(long long n)
{
	return (n<0)? '-' : '+';
}

long long absolute(long long n)
{
	return (n<0)? -n : n;
}

void number_set(long long n, struct number* ln)
{
	int i;
	
	ln->sign = get_sign(n);
	n = absolute(n);
	
	for(i=0;i<MAX_DIGITS;i++)
		ln->digits[i] = '0';
	for(i=MAX_DIGITS-1;i>-1;i--)
	{
		ln->digits[i] = n%10 + '0';
		n = n/10;
	}
	return;
}

void number_copy(struct number* dst, struct number* src)
{
	int i;
	dst->sign = src->sign;
	for(i=0;i<MAX_DIGITS;i++)
	{
		dst->digits[i] = src->digits[i];
	}
}

/*
 *	Return 0 if right is greater than left.
 *	Return 1 for all else.
 */
int compare_absolute_values(struct number* ln, struct number* rn)
{
	int i=0;

	while(ln->digits[i] == rn->digits[i] && i!=MAX_DIGITS)
		i++;
	
	return ((i==MAX_DIGITS) || ((ln->digits[i] - '0') >= (rn->digits[i] - '0')));
}

struct number* add_numbers(struct number* ln, struct number* rn)
{
	struct number* ans;
	struct number* bign;
	struct number* smalln;

	int carry,i,x;

	ans = malloc(sizeof(struct number));
	
	if(ln->sign == rn-> sign)
	{
		carry = 0;
		for(i=MAX_DIGITS-1;i>-1;i--)
		{
			x = ln->digits[i] - '0' + rn->digits[i] -'0' + carry;
			ans->digits[i] = x%10 + '0';
			carry = x/10;
		}
		ans->sign = ln->sign;
	}
	else
	{
		if(compare_absolute_values(ln, rn))
		{
			bign = ln;
			smalln = rn;
		}
		else
		{
			bign = rn;
			smalln = ln;
		}
		carry = 0;
		for(i=MAX_DIGITS-1;i>-1;i--)
		{
			x = (bign->digits[i] - '0') - (smalln->digits[i] - '0') + carry;
			carry = (x<0)? -1 : 0;
			x = (x<0)? x+10 : x;
			ans->digits[i] = x + '0';
		}
		ans->sign = bign->sign;

	}
	return ans;
}

struct number* subtract_numbers(struct number* ln, struct number* rn)
{
	struct number* ans;
	
	negate_number(rn);
	
	ans = add_numbers(ln, rn);

	negate_number(rn);
	
	return ans;
}

void scalar_mult(long long n, struct number* p)
{
	int i,carry,x;
	carry = 0;
	for(i=MAX_DIGITS-1;i>-1;i--)
	{
		x = n*(p->digits[i] - '0') + carry;
		p->digits[i] = x%10 + '0';
		carry = x/10;
	}
}

void decimal_shift(int n, struct number* p)
{
	int i;
	
	for(i=0;i<MAX_DIGITS-n;i++)
	{
		p->digits[i] = p->digits[i+n];
	}
	
	for(i=MAX_DIGITS-n;i<MAX_DIGITS;i++)
		p->digits[i] = '0';

}

struct number* multiply_numbers(struct number* ln, struct number* rn)
{
	struct number* ans;
	struct number* temp;

	ans = malloc(sizeof(struct number));
	temp = malloc(sizeof(struct number));
	
	number_set(0,ans);

	int i,j,carry,x,y;
	int d_shift;

	d_shift = 0;
	
	for(i=MAX_DIGITS-1;i>-1;i--)
	{
		x = ln->digits[i] - '0';
		carry = 0;
		number_set(0,temp);
		
		for(j=MAX_DIGITS-1;j>-1;j--)
		{
			y = carry + x*(rn->digits[j] - '0');
			temp->digits[j] = (y%10) + '0';
			carry = y/10;
		}
		
		decimal_shift(d_shift, temp);

		ans = add_numbers(ans, temp);

		d_shift++;
	}
	ans->sign = (ln->sign == rn->sign)? '+' : '-';
	return ans;
}

int number_is_equal(struct number* l, struct number* r)
{
	int i;
	for(i=0;i<MAX_DIGITS;i++)
		if(l->digits[i] != r->digits[i])
			return 0;
	return 1;

}

struct number* power_exec_long(struct number* a, long long n)
{
	struct number* ans;

	ans = malloc(sizeof(struct number));
	number_set(1, ans);
	
	while(n!=0)
	{
		ans = multiply_numbers(a, ans);
		n--;
	}

	return ans;
}

struct number* power_exec_number(struct number* x, struct number* pow)
{
	struct number* ans;
	struct number* tmp;
	struct number* one;

	ans = malloc(sizeof(struct number));
	tmp = malloc(sizeof(struct number));
	one = malloc(sizeof(struct number));

	number_set(1, ans);
	number_set(0, tmp);
	number_set(1, one);

	while(!number_is_equal(tmp, pow))
	{
		ans = multiply_numbers(ans, pow);
		add_numbers(one, tmp);
	}

	free(tmp);
	free(one);
	tmp = NULL;
	one = NULL;

	return ans;
}

#endif
