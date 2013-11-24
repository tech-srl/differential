typedef int bool;

extern int printf(char*,...);

#define STEP (2)

static void
print_numbers (long first, long last)
{
	char * fmt, * separator, * terminator;
	bool out_of_range = (last < first);
	if (!out_of_range) {
		long x = first;
		long i;

		for (i = 1; ; i++) {

			long x0 = x;
			printf (fmt, x);

			if (out_of_range) break;

			x = first + i * STEP;			
			out_of_range = (last < x);
			/**/
			if (out_of_range){
				bool print_extra_number;
				if (!print_extra_number) break;
			}

			printf(separator);
			

		}

		printf(terminator);
	}
}
