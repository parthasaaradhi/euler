#include<stdio.h>
int main()
{
	int x,y,z,i,n,first,lulz,total;
	lulz = 2;
	for(n=2;n<=10000;n++) {
		//printf("Lulz: %d\n", lulz);
		if(lulz*lulz == n) {
			lulz++;
		} else {
			y = lulz-1;
			x = lulz-1;
			z = 1;
			first = 0;
			while(!(y == lulz-1 && z == 1) || first==0) {
				first++;
				z = (n - y*y)/z;
				x = 1;
				while((z*x-y)*(z*x-y) < n)
					x++;
				x--;
				y=z*x-y;
				//printf("Iteration %d : %d : %d\n", x, y, z);
			}
			if(first%2 == 1)
				total++;
		}
	}
	printf("%d\n", total);
	return 0;
}
