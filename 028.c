#include<stdio.h>
int main() {
	long long s,i,x,y,z,w,n;
	s = 1;
	i = 2;
	w = 1;
	n = 1;
	//printf("1");
	while(n != 1001) {
		x = w+i;
		y = w+2*i;
		z = w+3*i;
		w = w+4*i;
		i = i+2;
		s = s + x + y + z + w;
		//printf(", %lld, %lld, %lld, %lld", x, y, z, w);
		n = n + 2;
	}
	printf("%lld\n", s);
	return 0;
}
