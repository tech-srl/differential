void f(int x) {
	int y = 0;
loop:	if (y<x) {
		y++;
		goto loop;
	}
}

