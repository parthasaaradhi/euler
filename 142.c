#include<stdio.h>
int is_perfect_square(long long n) {
	long long s=n/2;
	while(!(s*s == n || (n>s*s && n<(s+1)*(s+1))))
		s = (s + n/s)/2;
	return s*s==n? s : -1;
}
int main() {
	long long x,y,z,a,b,t;
	for(z=1;z<10000;z++) {
		for(a=1;a<10000;a++) {
			y=z+a*a;
			if(is_perfect_square(y+z) != -1) {
				for(b=1;b<10000;b++) {
					x = y+b*b;
					//printf("%lld %lld %lld\n", x, y, z);
					if(is_perfect_square(x+y) != -1 
							&& is_perfect_square(x-z) != -1 
							&& is_perfect_square(x+z) != -1)
						printf("%lld %lld %lld\n", x, y, z);
				}
			}
		}
	}
	return 0;
}
