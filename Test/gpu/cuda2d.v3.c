#define WIDTH 512
#define N 2

void kernel(int *Min, int *Mout, int tx, int ty) {
	tx = 0;
	ty = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			int x = 0, y = 0, a = 0, b = 0 , c = 0 , d = 0, e = 0, f = 0, t = 0;
			x = Min[(tx)*WIDTH+ty];
			y = Min[(tx+1)*WIDTH+ty+1];
			b = Min[(tx-1)*WIDTH+ty];
			c = Min[(tx+1)*WIDTH+ty];
			a = Min[(tx)*WIDTH+ty-1];
			d = Min[(tx)*WIDTH+ty+1];
			e = Min[(tx+2)*WIDTH+ty+1];
			f = Min[(tx+1)*WIDTH+ty+2];
			t = c + d;
			Mout[(tx)*WIDTH+ty] = 2 * (x + a + b + t);
			Mout[(tx+1)*WIDTH+ty+1] = 2 * (y + e + f + t);
		}
	}
}
