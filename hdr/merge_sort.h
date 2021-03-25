void inplace_merge_sort(int* S, int s, int f)
{
	if(f-s == 0 || f-s == 1)
		return;
	int l = s;
	int r = (f+s)/2;
	int i;
	int* temp;

	inplace_merge_sort(S, l, r);
	inplace_merge_sort(S, r, f);

	temp = malloc((f-s)*sizeof(int));

	for(i=0;i<f-s;i++)
	{
		if(l == (f+s)/2)
		{
			temp[i] = e[r];
			r++;
		} else if(r == f) {
			temp[i] = e[l];
			l++;
		} else {
			if(e[l] < e[r]) {
				temp[i] = e[l];
				l++;
			} else {
				temp[i] = e[r];
				r++;
			}
		}
	}

	for(i=s;i<f;i++)
		e[i] = temp[i-s];
	
	free(temp);
	temp = NULL;
	return;
}

void sort(int* S, int length)
{
	inplace_merge_sort(S, 0, length);
}
