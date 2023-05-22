#include<stdio.h>
#include<stdlib.h>
int abs(int a) {
	return a>=0 ? a : -1*a;
}

int gcd(int a, int b) {
	if(a>b) return gcd(b,a);
	if(a == 0) return b;
	return gcd(b%a, a);
}

int N[3025];

struct fraction {
	int numerator;
	int denominator;
};

void make_frac(struct fraction *f, int n) {
	f->numerator = n;
	f->denominator = 1;
	return;
}

struct fraction clean(struct fraction f) {
	int g;
	g = gcd(abs(f.numerator), abs(f.denominator));
	f.numerator = f.numerator/g;
	f.denominator = f.denominator/g;
	return f;
}

int get_int(struct fraction f) {
	f = clean(f);
	return f.denominator == 1 ? f.numerator : -1;
}

struct fraction plus (struct fraction a, struct fraction b) {
	struct fraction ans;
	ans.denominator = a.denominator*b.denominator;
	ans.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
	return ans;
}

struct fraction subt (struct fraction a, struct fraction b) {
	struct fraction ans;
	ans.denominator = a.denominator*b.denominator;
	ans.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
	return ans;
}

struct fraction mult (struct fraction a, struct fraction b) {
	struct fraction ans;
	ans.denominator = a.denominator*b.denominator;
	ans.numerator = a.numerator*b.numerator;
	return ans;
}

struct fraction divide (struct fraction a, struct fraction b) {
	struct fraction ans;
	ans.denominator = a.denominator*b.numerator;
	ans.numerator = a.numerator*b.denominator;
	return ans;
}

//-------------------------------------------------------------------------------------------
struct fraction (*fn[4])(struct fraction, struct fraction) = {plus,subt,mult,divide};
//-------------------

struct fraction apply(struct fraction (*f)(struct fraction, struct fraction), struct fraction a, struct fraction b) {
	return clean((*f)(a, b));
}

void all_trees(int* p, struct fraction(**f)(struct fraction, struct fraction)) {
	struct fraction fracs[4];
	int i,ans;
	for(i=0;i<4;i++)
		make_frac(&fracs[i], p[i]);

	ans = get_int(apply(f[1], apply(f[0], fracs[0], fracs[1]), apply(f[2], fracs[2], fracs[3])));
	if(ans > 0) N[ans] = 1;
	ans = get_int(apply(f[2], apply(f[1], apply(f[0], fracs[0], fracs[1]), fracs[2]), fracs[3]));
	if(ans > 0) N[ans] = 1;
	ans = get_int(apply(f[2], apply(f[0] ,fracs[0], apply(f[1], fracs[1], fracs[2])), fracs[3]));
	if(ans > 0) N[ans] = 1;
	ans = get_int(apply(f[0], fracs[0], apply(f[1], fracs[1], apply(f[2], fracs[2], fracs[3]))));
	if(ans > 0) N[ans] = 1;
	ans = get_int(apply(f[0], fracs[0], apply(f[1], apply(f[2], fracs[1], fracs[2]), fracs[3])));
	if(ans > 0) N[ans] = 1;
}


void recurse_fn(struct fraction (**f)(struct fraction, struct fraction), int idx, int* perm) {
	int i;
	if(idx == 3)
		all_trees(perm, f);
	else {
		for(i=0;i<4;i++) {
			f[idx] = fn[i];
			recurse_fn(f, idx+1, perm);
		}
	}
	return;
}

void fire_all_functions(int* perm) {
	struct fraction (*current_fns[3])(struct fraction, struct fraction);
	recurse_fn(current_fns, 0, perm);
	return;
}

void recurse_input(int* perm, int* p, int idx) {
	int i;
	if(idx==4)
		fire_all_functions(perm);
	else {
		for(i=0;i<4;i++)
			if(p[i]!=0) {
				perm[idx] = p[i];
				p[i] = 0;
				recurse_input(perm, p, idx+1);
				p[i] = perm[idx];
			}
	}
}

void check_all_permutations(int *p) {
	int perm[4];
	recurse_input(perm, p, 0);
}

int find_ans(int a, int b, int c, int d) {
	int p[4] = {a,b,c,d};
	int i;
	for(i=1;i<3025;i++) N[i] = 0;
	check_all_permutations(p);
	for(i=1;i<3025;i++)
		if(N[i] == 0) return i-1;
	return 3024;
}

int main() {
	int a,b,c,d;
	int ans;
	for(a=1;a<7;a++)
		for(b=a+1;b<8;b++)
			for(c=b+1;c<9;c++)
				for(d=c+1;d<10;d++) {
					ans  = find_ans(a,b,c,d);
					printf("%d %d %d %d %d\n", a,b,c,d,ans);
				}
	return 0;
}
