typedef int bool;

extern int printf(char*,...);

#define STEP (2)

static void
print_numbers (long first, long last)
{
	char * fmt, * separator, * terminator;
	long x = first, i = 1;
	bool out_of_range = 0;
	if (STEP < 0 && first < last) {
		out_of_range = 1;
	} else if (STEP >= 0 && last < first) {
		out_of_range = 1;
	}

	loop:
	if (out_of_range == 0) {

		printf (fmt, x);
		if (out_of_range == 1) {
			return;
		}

		x = first + i * STEP;
		if (STEP < 0 && first < last) {
			out_of_range = 1;
		} else if (STEP >= 0 && last < first) {
			out_of_range = 1;
		}
		printf (separator);

		i++;
		goto loop;
	}
	printf (terminator);

}

