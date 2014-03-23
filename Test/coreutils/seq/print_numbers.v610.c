extern int fputs(...);
extern int printf(...);
extern int STR(...);
extern int STREQ(...);
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
	int out_of_range = (last < first);
	int i = 0, x = 0, x0 = 0;
	if (!out_of_range) {
		x = first;
		for (i = 0; /* empty */1 ; i++) {
			x0 = x;
			printf (fmt, x);
			if (out_of_range) break;
			x = first + i * STEP;
			out_of_range = (last < x);
			if (out_of_range) {
				print_extra_number = STREQ(STR(x0),STR(x));
				if (print_extra_number)
					break;
			}
			fputs(separator,stdout);
		}
		fputs(terminator,stdout);
	}
}

