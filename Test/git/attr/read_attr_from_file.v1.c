#define NULL 0
#define ENOENT 1

extern int fopen(...);
extern int fgets(...);
extern int warning(...);
extern int strerror(...);
extern int handle_attr_line(...);
extern int fclose(...);
extern int read_attr_from_file(...);
extern int xcalloc(...);

static
int
read_attr_from_file(const char *path, int macro_ok, int errno)
{
	int fp = 0;
	int res = 0;
	char buf[2048];
	int lineno = 0;
	fp =fopen(path, "r");

	if (!fp) {
		if (errno != ENOENT)
			warning(("unable to access '%s': %s"), path, strerror(errno));
		return (res = NULL);
	}
	res = xcalloc(1, sizeof(res));
	while (fgets(buf, sizeof(buf), fp))
		handle_attr_line(res, buf, path, ++lineno, macro_ok);
	fclose(fp);
	return res;
}
