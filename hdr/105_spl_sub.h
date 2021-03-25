#include<stdio.h>
#include<stdlib.h>

int no_sel(int n)
{
	int x=0;
	while(n!=0)
	{
		x = x + n%2;
		n=n/2;
	}
	return x;
}

int sub_set_sum(int n, int* a)
{
	int s,i;
	s = 0;
	i = 0;
	while(n!=0)
	{
		s=s+n%2*a[i];
		n=n/2;
		i++;
	}
	return s;
}

int is_distinct(int* ss, int sup_length)
{
	int i,j;
	for(i=0;i<sup_length;i++)
		for(j=i+1;j<sup_length;j++)
			if(ss[i] == ss[j])
				return 1;
	return 0;
}

int is_condition2(int* maximas, int* minimas, int* ss, int length, int sup_length)
{
	int i,x;
	for(i=0;i<length+1;i++)
	{
		maximas[i] = 0;
		minimas[i] = 1000*1000;
	}
	for(i=0;i<sup_length;i++)
	{
		x = no_sel(i);
		minimas[x] = ss[i] < minimas[x] ? ss[i] : minimas[x];
		maximas[x] = ss[i] > maximas[x] ? ss[i] : maximas[x];
	}

	for(i=length;i>0;i--)
		if(minimas[i] <= maximas[i-1])
			return 1;
	return 0;
}

int speacial_subset_test(int l, int* k)
{
	int i,x,length,sup_length;
	int* a ;
	int* ss;
	int* maximas;
	int* minimas;

	length = l;
	sup_length = 1;
	
	for(i=0;i<length;i++)
		sup_length = 2 * sup_length;
	
	a = malloc(length*sizeof(int));
	ss = malloc(sup_length*sizeof(int));
	minimas = malloc((length+1)*sizeof(int));
	maximas = malloc((length+1)*sizeof(int));

	for(i=0;i<length;i++)
		a[i] = k[i];

	for(i=0;i<sup_length;i++)
		ss[i] = sub_set_sum(i,a);

	x = is_distinct(ss, sup_length);
	
	if(x == 0)
	{
		x = is_condition2(maximas, minimas, ss, length, sup_length);

		if(x==0)
		{
			x = 0;
			for(i=0;i<length;i++)
				x = x + a[i];
			return x;
		}
	}

	return 0;
}
