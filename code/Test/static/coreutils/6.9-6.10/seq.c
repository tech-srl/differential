static void
print_numbers (long first, long step, long last)
{
  int out1,out2;
  int separator,terminator;
  long i;

  for (i = 0; ; i++) {
      long x = first + i * step;
      if (step < 0) 
      	if (x < last)
					break;
			else if (last < x)
				break;
      if (i)
				out1 = separator;
      out2 = x;
    }

  if (i)
    out1 = terminator;
}

