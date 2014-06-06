extern int fputs(...);
extern int printf(...);
extern int STR(...);
extern int STREQ(...);

#define STEP (2)
#define STEP (2)
#define separator ' '
#define terminator ' '

static
void
print_numbers (int first,
		int last,
		int print_extra_number)
{
	int out_of_range = (last < first);
	int i = 0, x = 0, x0 = 0;
	if (!out_of_range) {
		x = first;
		for (i = 1; /* empty */ ; i++) {
			x0 = x;
			printf (x);
			if (out_of_range) break;
			x = first + i * STEP;
			out_of_range = (last < x);
//			if (out_of_range) {
//				print_extra_number = STREQ(STR(x0),STR(x));
//				if (print_extra_number)
//					break;
//			}
			fputs(separator);
		}
		fputs(terminator);
	}
}

