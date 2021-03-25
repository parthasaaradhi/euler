#ifndef FRACTION_H
#define FRACTION_H

#include "stdlib.h"

struct fraction 
{
	long long n;
	long long d;
};


long long absolute(long long n)
{
	return ((n<0)? -1*n : n);
}

long long gcd(long long x, long long y)
{

	if(x==y)
		return x;
	if(x==0)
		return y;
	if(y==0)
		return x;
	if(x>y)
		return gcd(x%y, y);
	else
		return gcd(x,y%x);
}

long long lcm(long long x, long long y)
{
	return (x*y)/gcd(x,y);
}

void fraction_print(struct fraction x)
{
	printf("%lld/%lld", x.n, x.d);
}

struct fraction irreducible(struct fraction x)
{
	long long g;
	if(x.n == 0)
	{
		x.d = 1;
		return x;
	}
	//printf("GCD: %lld : %lld\n", absolute(x.n), x.d);
	g = gcd(absolute(x.n),x.d);
	x.n = x.n/g;
	x.d = x.d/g;
	return x;
}

struct fraction fraction_inverse(struct fraction x)
{
	struct fraction ans;
	if (x.n < 0)
	{
		ans.d = -1*x.n;
		ans.n = -1*x.d;
	}
	else
	{
		ans.n = x.d;
		ans.d = x.n;
	}
	return ans;
}

struct fraction fraction_multiply(struct fraction x, struct fraction y)
{
	struct fraction ans;
	ans.n = x.n*y.n;
	ans.d = x.d*y.d;
	return irreducible(ans);
}

struct fraction fraction_divide(struct fraction x, struct fraction y)
{
	return fraction_multiply(x,fraction_inverse(y));
}

struct fraction fraction_add(struct fraction x, struct fraction y)
{
	struct fraction ans;
	ans.d = lcm(x.d, y.d);
	ans.n = x.n*ans.d/x.d+y.n*ans.d/y.d;
	return irreducible(ans);
}

struct fraction fraction_subtract(struct fraction x, struct fraction y)
{
	y.n = -1 * y.n;
	return fraction_add(x,y);
}

int fraction_equals(struct fraction x, struct fraction y)
{
	x = irreducible(x);
	y = irreducible(y);
	return (x.n == y.n && x.d == y.d);
}

struct fraction* convert_long_fraction_vector(long long* a, int n)
{
	int i;
	struct fraction* ans;
	ans = malloc(n*sizeof(struct fraction));
	for(i=0;i<n;i++)
	{
		ans[i].n = a[i];
		ans[i].d = 1;
	}
	return ans;
}

struct fraction** convert_long_fraction_matrix(long long** a, int n)
{
	int i,j;
	struct fraction** ans;
	ans = malloc(n*sizeof(struct fraction*));
	for(i=0;i<n;i++)
	{
		ans[i] = malloc(n*sizeof(struct fraction));
		for(j=0;j<n;j++)
		{
			ans[i][j].n = a[i][j];
			ans[i][j].d = 1;
		}
	}
	return ans;
}

#endif

