void f(int x) {
	int y = 0, z = 3;
loop:	if (y<x) {
		if (x%2 == 0)
			z = 2;
		y++;
		goto loop;
	}
}

