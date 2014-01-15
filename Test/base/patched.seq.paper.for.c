typedef int bool;

extern int printf(char*,...);

#define STEP (2)

static void
print_numbers (long first, long last, bool print_extra_number)
{
	char * fmt, * separator, * terminator;
	bool out_of_range = (last < first);
	long x,x0,i;
	if (!out_of_range) {
		x = first;

		for (i = 1; ; i++) {

			x0 = x;
			printf (fmt, x);

			if (out_of_range) break;

			x = first + i * STEP;			
			out_of_range = (last < x);
			/**/
			if (out_of_range){
				if (!print_extra_number) break;
			}
			printf(separator);
		}

		printf(terminator);
	}
}
