void f(int arr[], int x,int y,int z) {
	//z = x;
	//arr[1] = x;
	//arr[z] = 3;
	//y = arr[x];
	if (x > 0) {
		y = arr[z];
	} else {
		x = arr[z];
		z = x;
	}
}
