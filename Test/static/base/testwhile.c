int f(int x) {
	int y, i = 0;
	while (x > 0 && (x < 8 && i < 10)) {
		y = 9;
		++i;
	}
	return y;
}
