#include<stdio.h>
int digits[6];
int decs[10];
int seive[1000*1000];
void fillDigits(int n)
{
	int i;
	for(i=0;i<6;i++)
		digits[i] = 0;
	for(i=0;i<10;i++)
		decs[i] = 0;
	for(i=5;i>-1;i--)
	{
		digits[i] = n%10;
		decs[n%10]++;
		n = n/10;
	}
}
int testPrimes()
{
	int possible,i,j,x,lul;
	possible=-1;
	for(i=0;i<10;i++)
		if(decs[i] >= 3)
			possible = i;
	
	if(possible==-1)
		return 0;
	lul = 0;
	for(i=0;i<10;i++)
	{
		x = 0;
		for(j=0;j<6;j++) {
			if(digits[j] == possible && (j!=0 || i!=0)) {
				x = 10*x + i;

			} else {
				x = 10 * x + digits[j];
			}
		}
		if(seive[x] == 0)
			lul++;
	}
	return lul == 8 ? 1 : 0;
	
	
}
int main()
{
	int i,j,n;
	for(i=2;i<1000*1000;i++)
		seive[i] = 0;
	for(i=2;i<1000;i++)
		if(seive[i] == 0)
			for(j=i*i;j<1000*1000;j=j+i)
				seive[j] = 1;
	for(i=1000*100+1;i<1000*1000;i++)
		if(seive[i] == 0) {
			fillDigits(i);
			if(testPrimes(i) == 1) {
				printf("%d ", i);
				break;
			}
		}
	
	printf("\n");
	return 0;
}
