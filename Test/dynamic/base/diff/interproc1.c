int global = 1;

int goo() {
	return global++;
}

int foo(int x) {
	int y = x + 1;
	//goo();
	return y + 1;
}

int moo(int x, int y) {
	int z;
	foo(goo());
	return z = x + y;
}

int main() {
	int x = 42,y = 84;
	y = foo(x);
	return y;
}
