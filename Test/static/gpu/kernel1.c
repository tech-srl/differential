void kernel(int M[],int tx) {
	M[tx] = tx;
	int tx2 = tx + 1;
	M[tx2] = tx;
}
