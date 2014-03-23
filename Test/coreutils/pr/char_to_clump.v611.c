#define TAB_WIDTH(c_, h_) ((c_) - (MOD(h_,c_)))

extern MOD(...);
extern XOR(...);
extern write(...);
extern int isprint(...);
extern int sprintf(...);

static int
char_to_clump (
		char c,
		char *clump_buff,
		int input_position,
		int untabify_input,
		int width,
		int use_esc_sequence,
		int use_cntrl_prefix)
{
	char input_tab_char = '\t';
	int chars_per_input_tab = 8;
	unsigned char uc = c;
	char *s = clump_buff;
	int i = 0;
	char esc_buff[4];
	int chars = 0;
	int chars_per_c = 8;

	if (c == input_tab_char)
		chars_per_c = chars_per_input_tab;

	if (c == input_tab_char || c == '\t')
	{
		width = TAB_WIDTH (chars_per_c, input_position);

		if (untabify_input)
		{
			for (i = width; i; --i) {
				write(s,' ');
				s++;
			}
			chars = width;
		}
		else
		{
			write(s,c);
			chars = 1;
		}

	}
	else if (! isprint (uc))
	{
		if (use_esc_sequence)
		{
			width = 4;
			chars = 4;
			write(s,'\\');
			s++;
			sprintf (esc_buff, "%03o", uc);
			for (i = 0; i <= 2; ++i) {
				write(s,esc_buff[i]);
				s++;
			}
		}
		else if (use_cntrl_prefix)
		{
			if (uc < 0200)
			{
				width = 2;
				chars = 2;
				write(s,'^');
				s++;
				write(s,XOR(c,0100));
				s++;
			}
			else
			{
				width = 4;
				chars = 4;
				write(s,'\\');
				s++;
				sprintf (esc_buff, "%03o", uc);
				for (i = 0; i <= 2; ++i) {
					write(s,esc_buff[i]);
					s++;
				}
			}
		}
		else if (c == '\b')
		{
			width = -1;
			chars = 1;
			write(s,c);
		}
		else
		{
			width = 0;
			chars = 1;
			write(s,c);
		}
	}
	else
	{
		width = 1;
		chars = 1;
		write(s,c);
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
