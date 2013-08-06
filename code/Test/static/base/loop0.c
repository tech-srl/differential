void f(int x) {
	x = 0;
loop:	if (x < 3) {
		x++;
		goto loop;
	}
}

