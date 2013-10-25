
void f(int x) {
	x = 0;
	loop:
		x++;
		goto loop;
	return;
}

