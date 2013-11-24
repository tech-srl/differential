extern int printf(char*,...);

#define STEP (2)

static void
print_numbers (long first, long last)
{
	long i = 0,x = first + i * STEP;
	char * fmt, * separator, * terminator;
	loop:
	if (last < x) break;
	if (i) printf (separator);
	printf (fmt, x);
	i++;
	goto loop;

	if (i)
		printf (terminator);
}


