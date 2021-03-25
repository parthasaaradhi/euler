#include<stdio.h>
#include<stdlib.h>

int is_pandigital(int* l, int sn)
{
	int d[10];
	int i = 0;
	if(sn<10)
		return 1;
	for(i=0;i<10;i++)
		d[i] = 0;
	for(i=0;i<9;i++)
		d[l[i]]++;
	for(i=1;i<10;i++)
		if(d[i]!=1)
			return 1;

	while(l[sn-1] == 0)
		sn--;
	if(sn<11)
		return 1;	
	for(i=0;i<10;i++)
		d[i] = 0;

	for(i=1;i<10;i++)
		d[l[sn-i]]--;

	for(i=1;i<10;i++)
		if(d[i]!=-1)
			return 1;
	return 0;
}

int main()
{
	int* p;
        int* q;
	int sn,i,x,c,t;
	sn = 575;
	p = (int *) malloc(sn*sizeof(int));
	q = (int *) malloc(sn*sizeof(int));
	
	for(i=0;i<sn;i++)
	{
		p[i] = 0;
		q[i] = 0;
		t = 0;
	}

	p[0] = 1;
	q[0] = 1;
	x = 2;
	while(is_pandigital(q, sn) != 0 )
	{
		c = 0;
		for(i=0;i<sn;i++)
		{
			t = q[i];
			q[i] = q[i] + p[i] + c;
			c = q[i]/10;
			q[i] = q[i]%10;
		       	p[i] = t;	
		}
		if(c!=0)
		{
			p = (int *) realloc(p, (sn+10)*sizeof(int));
			q = (int *) realloc(q, (sn+10)*sizeof(int));
			for(i=sn;i<sn+10;i++)
			{
				q[i] = c%10;
				p[i] = 0;
				c = c/10;
			}
			sn = sn + 10;
		}
		x++;
	}
	//for(i=sn-1;i>-1;i--)
	//	printf("%d", q[i]);
	printf("\n");
	printf("Lolwa: %d\n", x);
	return 0;
}
