extern int fputs(...);
extern int printf(...);

#define STEP (2)
#define separator ' '
#define terminator ' '

static
void
print_numbers (int first,
		int last,
		int print_extra_number)
{
	int i = 0, x = 0;
	for (i = 0; /* empty */ ; i++) {
		x = first + i * STEP;
		if (last < x) break;
		if (i) fputs(separator);
		printf (x);
	}
	if (i)
		fputs(terminator);
}

