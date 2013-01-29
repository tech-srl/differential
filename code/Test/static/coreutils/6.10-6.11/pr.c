typedef int bool;

#define false (0)
#define true  (1)
#define TAB_WIDTH(c_, h_) ((c_) - ((h_) % (c_)))

extern bool isprint(char);
extern int sprintf(char *, const char *, ...);

static char *clump_buff;
static char input_tab_char = '\t';
static int chars_per_input_tab = 8;
static int input_position;
static bool untabify_input = false;
static bool use_esc_sequence = false;
static bool use_cntrl_prefix = false;

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
      width = TAB_WIDTH (chars_per_c, input_position);

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
  else if (! isprint (uc))
    {
      if (use_esc_sequence)
	{
	  width = 4;
	  chars = 4;
	  *s++ = '\\';
	  sprintf (esc_buff, "%03o", uc);
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
	      sprintf (esc_buff, "%03o", uc);
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
  else
    {
      width = 1;
      chars = 1;
      *s = c;
    }

  input_position += width;
  return chars;
}
