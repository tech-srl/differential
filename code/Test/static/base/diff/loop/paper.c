void foo(int *arr, int len) {
	int i = len - 1;
	i = i - 1;
	while (i) {
		arr[i] = i;
		i--;
	} 
}

