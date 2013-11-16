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
   Return 1 if the syscall succeeds, 0 if it fails but it's OK
   not to preserve ownership, -1 otherwise.  */

static int
set_owner (char const *dst_name, int dest_desc, uid_t uid, gid_t gid)
{
	static int HAVE_FCHOWN;
	static int fchown_dest_desc_uid_gid;
	static int chown_dst_name_uid_gid;
	static int chown_failure_ok_x;
	static int x_require_preserve;
	int r = 0;
	if (HAVE_FCHOWN && dest_desc != -1)
	{
		if (fchown_dest_desc_uid_gid == 0) {
			r = 1;
			return r;
		}
	}
	else
	{
		if (chown_dst_name_uid_gid == 0){
			r = 1;
			return r;
		}
	}

	if (! chown_failure_ok_x)
	{
		error (0, errno, _("failed to preserve ownership for %s"),
				quote (dst_name));
		if (x_require_preserve){
			r = -1;
			return r;
		}
	}

	r = 0;
	return r;
}
