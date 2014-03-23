/* Like fstatat, but cache the result.  If st_size is -1, the
   status has not been gotten yet.  If less than -1, fstatat failed
   with errno == -1 - st_size.  Otherwise, the status has already
   been gotten, so return 0.  */
static int
cache_fstatat (int fd, char const *file, int st_size, int st_ino, int flag, int errno, int fstatat)
{
	if (st_size == -1 && fstatat != 0)
	{
		st_size = -2;
		st_ino = errno;
	}
	if (0 <= st_size)
		return 0;
	errno = st_ino;
	return -1;
}

