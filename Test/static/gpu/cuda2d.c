#define WIDTH 512
#define N 1

void kernel(int *Min, int *Mout, int tx, int ty) {
	//int i = 0,j = 0;
	// v1 == Min[(tx+i)*WIDTH+ty+j]
	int v1;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			Mout[(tx+i)*WIDTH+ty+j] = 0.2 * v1;
}

