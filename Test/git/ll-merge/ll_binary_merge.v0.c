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

	if (opts_virtual_ancestor)
		stolen =  orig;
	else
		stolen = src1;

	result_ptr = stolen_ptr;
	result_size = stolen_size;
	stolen_ptr = NULL;
	return (Result = 1);
}
