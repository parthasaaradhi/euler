#include<stdlib.h>

/*
 * Numbers are Stored in Reverse Order
 * Prints are in right order
 * 12345 is stored as {5, [54321]}
 * Be Careful!!!!!*/

struct large_number
{
	int no;
	char* digits;
};

char conv_digi_char(int d)
{
	char c = d + '0';
	return c;
}

int conv_char_digi(char c)
{
	int d = c - '0';
	return d;
}

int get_number_of_digits(long long n)
{
	int x = 0;
	if(n==0)
		return 1;
	while(n!=0)
	{
		n=n/10;
		x++;
	}
	return x;
}

void set_number(long long n, struct large_number* ln)
{
	int i=0;
	ln.digits = realloc(ln.digits, get_number_of_digits(n)*sizeof(char));
	
	do
	{
		ln.digits[i] = conv_digi_char(n%10);
		n=n/10;
		i++;
	} while(n!=0);

	return;
}

struct large_number ordered_add(struct large_number lh, struct large_number rh)
{
	int i,x,carry;
	struct large_number ans;
	
	ans.no = 0;
	carry = 0;
	
	for(i=0;i<lh.no;i++)
	{
		x = conv_char_digi(lh.digits[i]) + conv_char_digi(rh.digits[i]) + carry;
		carry = x/10;
		x = x%10;
		ans.no++;
		ans.digits = realloc(ans.no*sizeof(char));
		ans.digits[ans.no-1] = conv_digi_char(x);
	}

	for(i=lh.no;i<rh.no;i++)
	{
		x = conv_char_digi(rh.digits[i]) + carry;
		carry = x/10;
		x = x%10;
		ans.no++;
		ans.digits = realloc(ans.no*sizeof(char));
		ans.digits[ans.no-1] = conv_digi_char(x);
	}

	while(carry!=0)
	{
		ans.no++;
		ans.digits = realloc(ans.no*sizeof(char));
		ans.digits[ans.no-1] = conv_digi_char(carry%10);
		carry = carry/10;
	}

	return ans;
}

struct large_number add(struct large_number lh, struct large_number rh)
{
	if(lh.no < rh.no)
		return ordered_add(lh,rh);
	else
		return ordered_add(rh, lh);
}

struct large_number ordered_multiply(struct large_number lh, struct large_number rh)
{
	struct large_number intermediate_ans[lh.no];
	struct large_number* ans;
	int i,j;
	for(i=0;i<lh.no;i++)
	{
		intermediate_ans[i] = scalar_multiply(rh[i], lh);
		for(j=0;j<i;j++)
			inplace_scalar_multiply(10, intermediate_ans[i]);
		ans = ordered_
	}
}

struct large_number multiply(struct large_number lh, struct large_number rh)
{
	if(lh.no < rh.no)
		return ordered_multiply(lh,rh);
	else
		return ordered_multiply(rh,lh);
}
