void kernel(int* M) {
	int tx = threadIdx.x;
	M[2*tx]++;
	M[2*tx+1]++;
}
