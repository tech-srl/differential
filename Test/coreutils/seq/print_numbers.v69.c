extern int fputs(...);
extern int printf(...);

#define STEP (2)

static
void
print_numbers (int first,
		int last,
		int fmt,
		int separator,
		int terminator,
		int stdout,
		int print_extra_number)
{
	int i = 0, x = 0;
	for (i = 0; /* empty */1 ; i++) {
		x = first + i * STEP;
		if (last < x) break;
		if (i) fputs(separator,stdout);
		printf (fmt, x);
	}
	if (i)
		fputs(terminator,stdout);
}

