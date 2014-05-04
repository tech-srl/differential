#define BLOCK_SIZE 32
#define wA 		8
#define wB 		8

// (0,0) <= (tx,ty) <= (BLOCK_SIZE,BLOCK_SIZE/2)

void kernel(int *C, int *A, int *B, int bx, int by, int tx, int ty, int *As, int *Bs) {
	// Index of the first sub-matrix of A processed by the block
	int aBegin = wA * BLOCK_SIZE * by;

	// Index of the last sub-matrix of A processed by the block
	int aEnd   = aBegin + wA - 1;

	// Step size used to iterate through the sub-matrices of A
	int aStep  = BLOCK_SIZE;

	// Index of the first sub-matrix of B processed by the block
	int bBegin = BLOCK_SIZE * bx;

	// Step size used to iterate through the sub-matrices of B
	int bStep  = BLOCK_SIZE * wB;

	// Csub is used to store the element of the block sub-matrix
	// that is computed by the thread {
	int Csub = 0, Csub2 = 0;
	for (int a = aBegin, b = bBegin; a <= aEnd ; a += aStep, b += bStep) {
		int as = A[a + wA * ty + tx];
		int bs = B[b + wB * ty + tx];
		As[BLOCK_SIZE*ty + tx] = as;
		Bs[BLOCK_SIZE*ty + tx] = bs;

		int as16 = A[a + wA * (ty+16) + tx];
		int bs16 = B[b + wB * (ty+16) + tx];

		As[BLOCK_SIZE*(ty+16) + tx] = as16;
		Bs[BLOCK_SIZE*(ty+16) + tx] = bs16;

		for(int k = 0; k < BLOCK_SIZE; ++k) {
			Csub += As[BLOCK_SIZE*ty+k] * Bs[BLOCK_SIZE*k+tx];
			Csub2 += As[BLOCK_SIZE*(ty+16)+k] * Bs[BLOCK_SIZE*k+tx];
		}
	}
	int c = wB * BLOCK_SIZE * by + BLOCK_SIZE * bx;
	C[c + wB * ty + tx] = Csub;
	C[c + wB * (ty+16) + tx] = Csub2;
}

