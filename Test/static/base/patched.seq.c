typedef int bool;

extern int printf(char*,...);

static void
print_numbers (long first, long step, long last)
{
	char * fmt, * separator;
	long x = first;
	bool out_of_range = 0;
	if (step < 0 && first < last) {
		out_of_range = 1;
	} else if (step >= 0 && last < first) {
		out_of_range = 1;
	}

	if (!out_of_range) {

		printf (fmt, x);
		if (out_of_range) {
			return;
		}

		x = first + step;
		if (step < 0 && x < last) {
			out_of_range = 1;
		} else if (step >= 0 && last < x) {
			out_of_range = 1;
		}

		if (out_of_range){
			bool print_extra_number; // print_extra_number is decided here
			// ...
			if (! print_extra_number) return;
		}
		printf ("%s",separator);
		printf (fmt, x);
		if (out_of_range) {
			return;
		}
	}
	return;
}

