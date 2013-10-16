void f(int x, int y, int z) {
	x = 0;
	loop:
	if (z > 0 && x < y) {
			x++;
			goto loop;
		}
	}
}

