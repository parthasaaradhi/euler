#include<stdio.h>
#include<stdlib.h>

int find(int* digits, int dn, int *a) {
	int j,i;
	j = dn-1;i=0;
	while(i!=3 && j!=-1) {
		if(digits[j] == a[i]) {
			i++;
		}
		j--;
	}
	if(i==3) return 1;
	return 0;
}

int main() {
	int i,j;int dn,ans,x;
	int * digits;
	long long p;
	int attempts[50][3];
	for(i=0;i<50;i++) {
		scanf("%d", &attempts[i][0]);
		attempts[i][2] = attempts[i][0]%10;
		attempts[i][1] = (attempts[i][0]%100)/10;
		attempts[i][0] = attempts[i][0]/100;
	}
	p = 1000;
	ans = 0;
	while(ans != 50) {
		x = p;
		dn=0;
		digits = malloc(0);
		while(x!=0) {
			dn++;
			digits = realloc(digits, dn*sizeof(int));
			digits[dn-1] = x%10;
			x = x/10;
		}
		ans = 0;
		for(i=0;i<50;i++) {
			x = 0;
			x = find(digits, dn, attempts[i]);
			ans = ans + x;
			if(x != 1)
				break;
		}
		free(digits);
		p++;
	}
	printf("%lld\n",p-1);
	return 0;
}
