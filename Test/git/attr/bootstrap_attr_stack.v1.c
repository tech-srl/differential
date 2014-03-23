#define NULL 0
#define GIT_ATTR_INDEX 1
#define GITATTRIBUTES_FILE 2
#define INFOATTRIBUTES_FILE 3

extern int read_attr_from_array(...);
extern int git_attr_system(...);
extern int home_config_paths(...);
extern int is_bare_repository(...);
extern int read_attr(...);
extern int xstrdup(...);
extern int debug_push(...);
extern int read_attr_from_file(...);
extern int xcalloc(...);
extern int git_etc_gitattributes(...);
extern int git_path(...);

static
void
bootstrap_attr_stack(
		int attr_stack,
		int builtin_attr,
		int git_attributes_file,
		int direction,
		int xdg_attributes_file)
{
	int elem = 0;
	int elem_origin = 0;
	int elem_prev = 0;	

	if (attr_stack)
		return;

	elem = read_attr_from_array(builtin_attr);
	elem_origin = NULL;
	elem_prev = attr_stack;
	attr_stack = elem;

	if (git_attr_system()) {
		elem = read_attr_from_file(git_etc_gitattributes(), 1);
		if (elem) {
			elem_origin = NULL;
			elem_prev = attr_stack;
			attr_stack = elem;
		}
	}

	if (!git_attributes_file) {
		home_config_paths(NULL, &xdg_attributes_file, "attributes");
		git_attributes_file = xdg_attributes_file;
	}
	elem = read_attr_from_file(git_attributes_file, 1);
	if (elem) {
		elem_origin = NULL;
		elem_prev = attr_stack;
		attr_stack = elem;
	}

	if (!is_bare_repository() || direction == GIT_ATTR_INDEX) {
		elem = read_attr(GITATTRIBUTES_FILE, 1);
		elem_origin = xstrdup("");
		elem_prev = attr_stack;
		attr_stack = elem;
		debug_push(elem);
	}

	elem = read_attr_from_file(git_path(INFOATTRIBUTES_FILE), 1);
	if (!elem)
		elem = xcalloc(1, sizeof(elem));
	elem_origin = NULL;
	elem_prev = attr_stack;
	attr_stack = elem;
}
