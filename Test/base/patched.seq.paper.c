typedef int bool;

extern int printf(char*,...);

#define STEP (2)

static void
print_numbers (long first, long last)
{
	char * fmt, * separator, * terminator;
	long x = first, i = 1;
	bool out_of_range = 0, print_extra_number;
	if (last < first) {
		out_of_range = 1;
	}

	loop:
	if (out_of_range == 0) {

		printf (fmt, x);
		if (out_of_range == 1) {
			return;
		}

		x = first + i * STEP;
		if (last < first) {
			out_of_range = 1;
		}
		printf (separator);
		if (out_of_range == 1) {
			// print_extra_number is decided somehow...
			if (! print_extra_number)
				break;
		}
		i++;
		goto loop;
	}
	printf (terminator);

}

