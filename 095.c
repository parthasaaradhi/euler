#include<stdio.h>
#define M 1000*1000

long long set_min(long long x, long long y)
{
	return x<y? x : y;
}

struct myans {
	long long length;
	int p;
	long long smallest_no;

};

long long sum_divisors[M];
long long check[M];

struct myans recur(long long n, long long x)
{
	struct myans m;
	m.length = 0;
	m.p = 0;
	m.smallest_no = n;
	if(sum_divisors[n]>M)
		return m;
	else {
		if(check[sum_divisors[n]] == 1)
		{

			/*for(s=2;s<M;s++)
			  if(check[s]==1)
			  printf("Smallest %lld\n", s);
			  */
			m.length = 1;
			if(sum_divisors[n] == x)
				m.p = 1;
			else
				m.p = 0;
			return m;
		}
		else {
			check[sum_divisors[n]] = 1;
			m = recur(sum_divisors[n],x);
			m.length++;
			m.smallest_no = set_min(m.smallest_no, n);
			check[sum_divisors[n]] = 0;
		}
	}
	return m;
}

int main()
{

	long long i,j;
	struct myans l;
	long long setl;
	long long gl;
	long long small;

	for(i=0;i<M;i++)
	{
		sum_divisors[i]=1;
	}

	for(i=2;i<M;i++)
	{
		if(i*i<M)
			sum_divisors[i*i] = sum_divisors[i*i] + i;
		for(j=i+1;(i*j)<M;j++)
			sum_divisors[i*j] = sum_divisors[i*j] + i + j;
	}

	for(j=0;j<M;j++)
		check[j] = 0;

	small = M;
	gl = 0;
	setl = 0; // At what length, is the smallest number among the chain set.
	// If it is set at smaller legth, then small should be changed regardless when we go to higher length.

	for(i=2;i<M;i++)
	{
		check[i] = 1;
		l = recur(i,i);
		if(l.p == 1)
		{
			if(l.length>=gl)
			{
				gl = l.length;
				if(setl<gl)
					small = l.smallest_no;
				else
					small = set_min(small, l.smallest_no);
			}
			//printf("%lld : %lld : %d : %lld\n", i, l.length, l.p, l.smallest_no);
		}
		check[i] = 0;
	}
	printf("%lld\n", small);
	return 0;
}
