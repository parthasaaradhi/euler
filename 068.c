#include<stdio.h>
// 5*Sum -2(inner_sum) + inner_sum = sigma_10
// inner_sum should be multiple of 5
// 14 <= Sum <= 18
//            \         /
//              c      /
//       d            b
//      /
//     /    a   s-10-a____10
//    /       \
//             \
//

int digits[11];
int s;
int inner[5];
int outer[5];

void clean_digits() {
	int i;
	for(i=1;i<11;i++)
		digits[i] = 0;
	for(i=0;i<5;i++) {
		inner[i] = 0;
		outer[i] = 0;
	}
	return;
}

void print_permutation(int n, int prev) {
	int i,j;
	if(n==5) {
		for(j=1;j<11;j++) {
			if(digits[j] == 0 && inner[0]+inner[4]+j == s) {
				outer[0] = j;
				printf(" Inner:");
				for(i=0;i<5;i++) {
					printf("%d ", inner[i]);
				}
				printf("Outer:");
				for(i=0;i<5;i++)
					printf("%d ", outer[i]);
				printf("\n");
				outer[0] = 0;
			}
		}
		return;
	}
	for(i=1;i<11;i++) {
		if(digits[i] == 0) {
			digits[i] = 1;
			if (s-prev-i>0 && s-prev-i<11 && digits[s-prev-i] == 0) {
				digits[s-prev-i] = 1;
				inner[n] = i;
				outer[n] = s-prev-i;
				print_permutation(n+1, i);
				inner[n] = 0;
				outer[n] = 0;
				digits[s-prev-i] = 0;
			}
			digits[i] = 0;
		}
	}
}

int main() {
	int i,prev;
	digits[0] = -1;
	for(s=14;s<19;s++) {
		clean_digits();
		printf("Permutation for s: %d\n", s);
		for(i=1;i<9;i++) {
			digits[i] = 1;
			digits[10] = 1;
			inner[0] = i;
			outer[1] = 10;
			if(s-10-i>0 && s-10-i<11 && digits[s-10-i] == 0) {
				inner[1] = s-10-i;
				digits[s-10-i] = 1;
				print_permutation(2, inner[1]);
				digits[s-10-i] = 0;
				inner[1] = 0;
			}
			inner[0] = 0;
			outer[1] = 0;
			digits[i] = 0;
		}
	}
	return 0;
}
