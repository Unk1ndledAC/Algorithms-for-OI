void quick_sort(int *a, int low, int high){
	int i = low,j = high,key = a[i];
	while (i < j){					
		while(i < j && a[j] >= key)
			j--;
		a[i] = a[j];	
		while(i < j && a[i] <= key)
			i++;
		a[j] = a[i];
	}
	a[i] = key;
	if (i-1 > low) 
		quick_sort(a, low, i-1);
	if (i+1 < high)
		quick_sort(a, i+1, high);
    return;
}
