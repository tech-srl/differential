#define BLOCK_SIZE 	8
#define wA 		128
#define wB 		256

// (0,0) <= (tx,ty) <= (BLOCK_SIZE,BLOCK_SIZE)

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
	int Csub = 0;
	int a = aBegin, b = bBegin;
	for (; a <= aEnd ; ) {
		int as = A[a + wA * ty + tx];
		int bs = B[b + wB * ty + tx];
		As[BLOCK_SIZE*ty + tx] = as;
		Bs[BLOCK_SIZE*ty + tx] = bs;
		

		/*
		for(int k = 0; k < BLOCK_SIZE; ++k) {
			as = As[BLOCK_SIZE*ty+k];
			bs = Bs[BLOCK_SIZE*k+tx];
			Csub += as; // As[BLOCK_SIZE*ty+k] * Bs[BLOCK_SIZE*k+tx];
		}
		*/
		
		/*
		int k = 0;
		if (1) {
			k = 0;
			as = As[BLOCK_SIZE*ty+k];
			bs = Bs[BLOCK_SIZE*k+tx];
			Csub += as; // as * bs
		}

		
		if (1) {
			k = 1;
			as = As[BLOCK_SIZE*ty+k];
			bs = Bs[BLOCK_SIZE*k+tx];
			Csub += as; // as * bs
		}
		/*
		if (1) {
			k = 2;
			as = As[BLOCK_SIZE*ty+k];
			bs = Bs[BLOCK_SIZE*k+tx];
			Csub += as; // as * bs
		}
		*/

		a += aStep;
		b += bStep;
	}
	int c = wB * BLOCK_SIZE * by + BLOCK_SIZE * bx;
	C[c + wB * ty + tx] = Csub;
}
