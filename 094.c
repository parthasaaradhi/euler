#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>

int is_perfect_square(mpz_t n) {
	int ans;
	ans = 0;
	mpz_t temp_three,temp_one,temp_two;
	mpz_inits(temp_one, temp_two, temp_three, NULL);
	mpz_fdiv_q_ui(temp_three, n, 2);
	mpz_mul(temp_one, temp_three, temp_three);
	while(mpz_cmp(temp_one, n) != 0) {
		mpz_add(temp_one, temp_one, n);
		mpz_mul_ui(temp_two, temp_three, 2);
		mpz_fdiv_q(temp_three, temp_one, temp_two);
		mpz_mul(temp_one, temp_three, temp_three);
		mpz_add_ui(temp_two, temp_three, 1);
		mpz_mul(temp_two, temp_two, temp_two);
		if((mpz_cmp(temp_one, n)<0) && (mpz_cmp(temp_two, n)>0)) {
			ans = -1;
			break;
		}
	}
	mpz_clears(temp_three, temp_one, temp_two, NULL);
	return ans;
}
int main() {
	mpz_t a,s,ans,temp;
	int h;
	mpz_inits(a, s, ans, temp, NULL);
	mpz_set_si(a, 3);
	do {
		mpz_mul(s, a, a);
		mpz_add_ui(temp, a, 1);
		mpz_fdiv_q_ui(temp, temp, 2);
		mpz_submul(s, temp, temp);
		h = is_perfect_square(s);
		if(h==0) {
			mpz_mul_ui(temp, a, 3);
			mpz_add_ui(temp, temp, 1);
			mpz_add(ans, ans, temp);
			mpz_add_ui(temp, a, 1);
			gmp_printf("%Zd %Zd %Zd\n", a, a, temp);
		}
		mpz_mul(s, a, a);
		mpz_sub_ui(temp, a, 1);
		mpz_fdiv_q_ui(temp, temp, 2);
		mpz_submul(s, temp, temp);
		h = is_perfect_square(s);
		if(h==0) {
			mpz_mul_ui(temp, a, 3);
			mpz_sub_ui(temp, temp, 1);
			mpz_add(ans, ans, temp);
			mpz_sub_ui(temp, a, 1);
			gmp_printf("%Zd %Zd %Zd\n", a, a, temp);
		}
		mpz_add_ui(a, a, 2);
	} while(mpz_cmp_si(a, 333333334) < 0);
	gmp_printf("%Zd\n", ans);
	mpz_clears(a,s,ans,temp,NULL);
	return 0;
}
