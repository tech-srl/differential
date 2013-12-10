#define WIDTH 512
#define N 2

void kernel(int *Min, int *Mout, int tx, int ty, int val) {
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			Mout[(tx+i)*WIDTH+ty+j] = 2 * val + ty + (3*j);
}

