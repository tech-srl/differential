int f(int x) {
	int y, i = 0;
	do {
		y = 9;
		++i;
	} while (x > 0 && (x < 8 && i < 10));
	return y;
}
