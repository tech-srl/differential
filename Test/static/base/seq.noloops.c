extern int printf(char*,...);

static void
print_numbers (long first, long step, long last)
{
	char * fmt, * separator;
	long x = first;
	if (step < 0 && x < last) {
			return;
	} else if (step >= 0 && last < x) {
			return;
	}

	printf (fmt, x);

	x = first + step;
	if (step < 0 && x < last) {
			return;
	} else if (step >= 0 && last < x) {
			return;
	}
	printf ("%s",separator);
	printf (fmt, x);
	return;
}

