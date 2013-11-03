
void f(int x) {
	loop:
	if (200 < 42 && x > 9) {
		return;
	} else if (x > -900 && x < -32) {
		return;
	}
	x++;
	goto loop;
	return;
}

