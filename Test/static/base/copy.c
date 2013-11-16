#define error(...)
#define true 1
#define false 0

typedef int uid_t;
typedef int gid_t;
typedef int bool;

/* Set the owner and owning group of DEST_DESC to the st_uid and
   st_gid fields of SRC_SB.  If DEST_DESC is undefined (-1), set
   the owner and owning group of DST_NAME instead.  DEST_DESC must
   refer to the same file as DEST_NAME if defined.
   Return true if the syscall succeeds, or if it's ok not to
   preserve ownership.  */

static bool
set_owner (char const *dst_name, int dest_desc, uid_t uid, gid_t gid)
{
	static int HAVE_FCHOWN;
	static int fchown_dest_desc_uid_gid;
	static int chown_dst_name_uid_gid;
	static int chown_failure_ok_x;
	static int x_require_preserve;
	int r = true;
	if (HAVE_FCHOWN && dest_desc != -1)
	{
		if (fchown_dest_desc_uid_gid == 0) {
			r = true;
			return r;
		}
	}
	else
	{
		if (chown_dst_name_uid_gid == 0) {
			r = true;
			return r;
		}
	}

	if (! chown_failure_ok_x)
	{
		error (0, errno, _("failed to preserve ownership for %s"),
				quote (dst_name));
		if (x_require_preserve) {
			r = true;
			return r;
		}
	}

	return r;
}
