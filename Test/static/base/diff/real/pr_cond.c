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

  input_position += width;
  return chars;
}

