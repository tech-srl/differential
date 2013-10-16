extern int printf(char*,...);

static void
print_numbers (long first, long step, long last)
{
	long i,x;
	char * fmt, * separator, * terminator;
	i = 0;
loop:
	x = first + i;
	/*
	if (step < 0 && x < last) {
		return;
	} else if (step >= 0 && last < x) {
		return;
	}
	if (i)
		printf ("%s",separator);
	printf (fmt, x);
	*/
	i++;
	goto loop;
	/*
	if (i)
		printf ("%s",terminator);
	return;
	*/
}

