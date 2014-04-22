#define WIDTH 512

void kernel(int M[], int width, int height, int tx, int ty) { // width and height are even
	int val = 0;
	if (tx == 0 || tx == 2) {
		if (((tx == 0) && (ty == 2 || ty == 0)) || ((tx == 2) && (ty == 1 || ty == 3))) {
			val = M[WIDTH*tx+ty];
			if (tx+1 < height)
				M[WIDTH*(tx+1)+ty] = val;
			if (tx-1 >= 0)
				M[WIDTH*(tx-1)+ty] = val;
			if ((ty+1 < width) && (ty == 2 || ty == 0))
				M[WIDTH*tx+(ty+1)] = val;
			if ((ty-1 >= 0) && (ty == 1 || ty == 3))
				M[WIDTH*tx+ty-1] = val;
		}
	}
}
