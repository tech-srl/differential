static void
print_numbers (long first, long step, long last)
{
  int out1,out2;
  int separator,terminator;
  int out_of_range = 0;
  int print_extra_number;
  if (step < 0) 
   	if (first < last)
			out_of_range = 1;
	else if (last < first)
		out_of_range = 1;

  if (out_of_range == 0) {
      long x = first;
      long i;

      for (i = 1; ; i++) {
				long x0 = x;
				out2 = x;
				if (out_of_range == 1)
					break;
				x = first + i * step;
				out_of_range = 0;
				if (step < 0) 
				 	if (x < last)
						out_of_range = 1;
				else if (last < x)
					out_of_range = 1;

				if (out_of_range == 1)
					if (print_extra_number == 1)
				 	  out1 = separator;
			}
      out1 = terminator;
  }
}

