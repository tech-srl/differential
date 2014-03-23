#define NULL 0
#define XDL_MERGE_FAVOR_OURS 1
#define XDL_MERGE_FAVOR_THEIRS 2

extern int assert(...);
extern int warning(...);

static int ll_binary_merge(int drv_unused,
		int result,
		const char *path,
		int orig, const char *orig_name,
		int src1, const char *name1,
		int src2, const char *name2,
		int opts,
		int marker_size,
		int opts_virtual_ancestor,
		int opts_variant,
		int result_ptr,
		int result_size,
		int stolen,
		int stolen_size,
		int stolen_ptr)
{
	int Result = 0;
	assert(opts);

	/*
	 * The tentative merge result is the or common ancestor for an internal merge.
	 */
	if (opts_virtual_ancestor) {
		stolen = orig;
	}
	else if (opts_variant == XDL_MERGE_FAVOR_OURS) {
		stolen = src1;
	}
	else if (opts_variant == XDL_MERGE_FAVOR_THEIRS) {
		stolen = src2;
	} else  {
		warning("Cannot merge binary files: %s (%s vs. %s)",
				path, name1, name2);
		stolen = src1;
	}

	result_ptr = stolen_ptr;
	result_size = stolen_size;
	stolen_ptr = NULL;

	/*
	 * With -Xtheirs or -Xours, we have cleanly merged;
	 * otherwise we got a conflict.
	 */
	if (opts_variant)
		return (Result = 0);
	else
		return (Result = 1);
}
