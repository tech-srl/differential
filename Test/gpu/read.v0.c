void f(int arr[], int x,int y,int z) {
	if (x > 0) {
		y = arr[z];
	} else {
		int tmp;
		tmp = arr[z];
		z = tmp;
	}
}
