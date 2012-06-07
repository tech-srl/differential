typedef unsigned size_t;
typedef enum { false, true } bool;
#define ISWHITE(c) (c == ' ')

static bool
bsd_split_3 (char *s, size_t s_len)
{
  size_t i;

  if (s_len == 0)
    return false;

  i = s_len - 1;
  while (i)
    i--;
    
    /*

  if (s[i] != ')')
    return false;

  s[i++] = '\0';

  while (ISWHITE (s[i]))
    i++;

  if (s[i] != '=')
    return false;

  i++;

  while (ISWHITE (s[i]))
    i++;

  *hexdigest = (unsigned char *) &s[i];
  */
  return true;
}
