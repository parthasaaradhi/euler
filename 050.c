#include<stdio.h>
int main()
{
	int seive[1000*1000];
	long long i,j,s,temp,count,mp;
	s = 0;
	mp = 2;
	for(i=2;i<1000*1000;i++)
		seive[i] = 0;
	for(i=2;i<1000;i++)
		if(seive[i] == 0)
			for(j=i*i;j<1000*1000;j=j+i)
				seive[j] = 1;
	for(i=2;i<1000*1000;i++)
		if (seive[i] == 0) {
			temp = i;
			count = 1;
			for(j=i+1;j<1000*1000;j++) {
				if(seive[j] == 0) {
					if (temp+j >= 1000*1000) {
						break;
					} else {
						count++;
						temp = temp + j;
						if(seive[temp] == 0) {
							if(count > s) {
								s = count;
								mp = temp;
							}
						}
					}
				}
			}
		}
	printf("%lld %lld\n",s, mp);
	return 0;
}
