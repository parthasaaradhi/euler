void lol(int*a, int i, int x, int n, int t)
{
	if(i==n)
		return;
	while(t<x && i<n)
	{
		t = 10*t + a[i];
		i++;
	}
	printf("%d", t/x);
	t=t%x;
	lol(a, i, x, n, t);
}
void long_divison_call(int* a, int x, int n)
{
	lol(a, 0, x, n, 0);
	return;
}
