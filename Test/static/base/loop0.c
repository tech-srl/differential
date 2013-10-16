void f(int x, int y) {
	x = 0;
	loop:
	if (x < y) {
		x++;
		goto loop;
	}
}

