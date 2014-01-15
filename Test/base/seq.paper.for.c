extern int printf(char*,...);

#define STEP (2)

static void
print_numbers (long first, long last)
{
	long i,x;
	char * fmt, * separator, * terminator;
	for (i = 0; /* empty */; i++) {
		x = first + i * STEP;
		if (last < x) break;
		if (i) printf (separator);
		printf (fmt, x);
	}
	if (i)	printf (terminator);
}

