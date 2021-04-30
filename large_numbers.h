#include "stdlib.h"

struct large_number {
	char sign; // + or - should implement later.
	int length;
	char* digits;
};

void set_number(struct* large_number ln, long long n)
{
	ln->length = 0;
	ln->digits = malloc(1*sizeof(char));
	
	if(n == 0)
	{
		ln->length++;
		ln->digits[0] = '0';
		return;
	}

	while(n!=0)
	{
		ln->length++;
		ln->digits = realloc(ln->digits, ln->length*sizeof(char));
		ln->digits[ln->length-1] = n%10 + '0';
		n = n/10;
	}
	return;
}

void ln_plus_plus(struct* large_number ln)
{
	int i,carry;
	carry = 1;
	int x;
	for(i=0;i<ln->length;i++)
	{
		x = ln->digits[i] - '0' + carry;
		ln->digits[i] = x%10 + '0';
		carry = x/10;
	}
	
	while(carry!=0)
	{
		ln->length++;
		ln->digits = realloc(ln->digits, ln->length*sizeof(char));
		ln->digits[ln->length-1] = carry%10 + '0';
		carry = carry/10;
	}

	return;
}

void ln_multiply_scalar(struct* large_number ln, long long n)
{
	int i,carry;
	carry = 0;
	long long x;
	
	for(i=0;i<ln->length;i++)
	{
		x = (n*(ln->digits[i] - '0') + carry);
		ln->digits[i] = x%10 + '0';
		carry = x/10;
	}
	
	while(carry!=0)
	{
		ln->length++;
		ln->digits = realloc(ln->digits, ln->length*sizeof(char));
		ln->digits[ln->length-1] = carry%10 + '0';
		carry = carry/10;
	}
	return;
}

