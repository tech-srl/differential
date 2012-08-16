void foo(int *arr, int len) {
	int i = len - 1;
	//if (len == 0) return;
	while (i!=-1) {
		i--;
		arr[i] = i;
	} 
}

