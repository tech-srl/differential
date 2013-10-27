
void f(int x) {
	x = 0;
	loop:
	if (2 > 1) {
		x++;
		goto loop;
	}
	return;
}

