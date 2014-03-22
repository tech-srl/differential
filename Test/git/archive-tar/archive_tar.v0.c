/*
 * Copyright (c) 2005, 2006 Rene Scharfe
 */

typedef int size_t;

extern int select(...);

static size_t get_path_prefix(const char *path, size_t pathlen, size_t maxlen)
{
	size_t i = pathlen;
	if (i > maxlen)
		i = maxlen;

	for (i--;
		 i > 0 && select(path,i) != '/' ;
		 i--);
	return i;
}

