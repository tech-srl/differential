typedef int bool;
typedef int size_t;

#define false (0)
#define true  (1)
#define ISWHITE(c) ((c) == ' ' || (c) == '\t')

static bool
bsd_split_3 (char *s, size_t s_len, unsigned char **hex_digest, char **file_name)
{
  size_t i;

  *file_name = s;

  /* Find end of filename. The BSD 'md5' and 'sha1' commands do not escape
     filenames, so search backwards for the last ')'. */
  i = s_len - 1;
  loop1:
  if (i != 0 && s[i] != ')') {
    i--;
    goto loop1;
  }

  if (s[i] != ')')
    return false;

  s[i++] = '\0';

  loop2:
  if (ISWHITE (s[i])) {
    i++;
    goto loop2;
  }

  if (s[i] != '=')
    return false;

  i++;

  loop3:
  if (ISWHITE (s[i])) {
    i++;
    goto loop3;
  }

  *hex_digest = (unsigned char *) &s[i];
  return true;
}

