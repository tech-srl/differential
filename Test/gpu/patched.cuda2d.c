#define WIDTH 512
#define N 2

void kernel(int *Min, int *Mout, int tx, int ty) {
	tx = 0;
	ty = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			int x = 0, a = 0, b = 0 , c = 0 , d = 0;
			x = Min[(tx+i)*WIDTH+ty+j];
			b = Min[(tx+i-1)*WIDTH+ty+j];
			c = Min[(tx+i+1)*WIDTH+ty+j];
			a = Min[(tx+i)*WIDTH+ty+j-1];
			d = Min[(tx+i)*WIDTH+ty+j+1];
			Mout[(tx+i)*WIDTH+ty+j] = 2 * (x + a + b + c + d);
		}
	}
}
