int input_position;
int chars_per_input_tab;
int untabify_input;
int use_esc_sequence;
int use_cntrl_prefix;
char input_tab_char;
char * clump_buff;

static int
char_to_clump (char c)
{
  unsigned char uc = c;
  char *s = clump_buff;
  int i;
  char esc_buff[4];
  int width;
  int chars;
  int chars_per_c = 8;
 
  if (c == input_tab_char)
    chars_per_c = chars_per_input_tab;

  if (c == input_tab_char || c == '\t')
    {
      width = ((chars_per_c) - ((input_position) % (chars_per_c)));

      if (untabify_input)
			{
				for (i = width; i; --i)
					*s++ = ' ';
				chars = width;
			}
				  else
			{
				*s = c;
				chars = 1;
			}

    }    
	  else if (uc)
    {
      if (use_esc_sequence)
			{
				width = 4;
				chars = 4;
				*s++ = '\\';
				for (i = 0; i <= 2; ++i)
					*s++ = esc_buff[i];
			}
		  else if (use_cntrl_prefix)
			{
				if (uc < 0200)
					{
					  width = 2;
					  chars = 2;
					  *s++ = '^';
					  *s++ = c ^ 0100;
					}
				else
					{
					  width = 4;
					  chars = 4;
					  *s++ = '\\';
					  for (i = 0; i <= 2; ++i)
							*s++ = esc_buff[i];
					}
			}
		  else if (c == '\b')
			{
				width = -1;
				chars = 1;
				*s = c;
			}
		  else
			{
				width = 0;
				chars = 1;
				*s = c;
			}
    }
  /* Too many backspaces must put us in position 0 -- never negative.  */
  if (width < 0 && input_position == 0)
    {
      chars = 0;
      input_position = 0;
    }
  else if (width < 0 && input_position <= -width)
    input_position = 0;
  else
    input_position += width;

  return chars;
}

int main(int argc, char ** argv) {
  return char_to_clump('c');
}
