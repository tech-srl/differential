#define WIDTH 512
#define N 1

void kernel(int *Min, int *Mout, int tx, int ty) {
	tx = 0;
	ty = 0;
	if (1) {
			int x = 0, a = 0, b = 0 , c = 0 , d = 0;
			x = Min[(tx)*WIDTH+ty];
			b = Min[(tx-1)*WIDTH+ty];
			c = Min[(tx+1)*WIDTH+ty];
			a = Min[(tx)*WIDTH+ty-1];
			d = Min[(tx)*WIDTH+ty+1];
			Mout[(tx)*WIDTH+ty] = 2 * (x + a + b + c + d);
	}
	tx = 0;
	ty = 1;
	if (1) {
			int x = 0, a = 0, b = 0 , c = 0 , d = 0;
			x = Min[(tx)*WIDTH+ty];
			b = Min[(tx-1)*WIDTH+ty];
			c = Min[(tx+1)*WIDTH+ty];
			a = Min[(tx)*WIDTH+ty-1];
			d = Min[(tx)*WIDTH+ty+1];
			Mout[(tx)*WIDTH+ty] = 2 * (x + a + b + c + d);
	}
	tx = 1;
	ty = 0;
	if (1) {
			int x = 0, a = 0, b = 0 , c = 0 , d = 0;
			x = Min[(tx)*WIDTH+ty];
			b = Min[(tx-1)*WIDTH+ty];
			c = Min[(tx+1)*WIDTH+ty];
			a = Min[(tx)*WIDTH+ty-1];
			d = Min[(tx)*WIDTH+ty+1];
			Mout[(tx)*WIDTH+ty] = 2 * (x + a + b + c + d);
	}
	tx = 1;
	ty = 1;
	if (1) {
			int x = 0, a = 0, b = 0 , c = 0 , d = 0;
			x = Min[(tx)*WIDTH+ty];
			b = Min[(tx-1)*WIDTH+ty];
			c = Min[(tx+1)*WIDTH+ty];
			a = Min[(tx)*WIDTH+ty-1];
			d = Min[(tx)*WIDTH+ty+1];
			Mout[(tx)*WIDTH+ty] = 2 * (x + a + b + c + d);
	}
}

