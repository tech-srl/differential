#define NULL 0
#define DATE_RFC2822 2822

struct strbuf { int buf; int len; };
struct strbuf STRBUF_INIT = {0,0};

extern int upstream_mark(...);
extern int ambiguous_path(...);
extern int interpret_branch_name(...);
extern int get_sha1_1(...);
extern int dwim_ref(...);
extern int dwim_log(...);
extern int warning(...);
extern char * xstrndup(...);
extern int approxidate_careful(...);
extern int read_ref_at(...);
extern int die(...);
extern int free(...);
extern int show_date(...);
extern int get_sha1_hex(...);
extern int select(...);



static int get_sha1_basic(const char *str, int len, unsigned char *sha1, int warn_ambiguous_refs)
{
	static const char *warn_msg = "refname '%.*s' is ambiguous.";
	char *real_ref = NULL;
	int refs_found = 0;
	int at = 0, reflog_len = 0;

	int get_sha1_hex_val = 0;
	get_sha1_hex_val = get_sha1_hex(str, sha1);
	if (len >= 40 && get_sha1_hex_val >= 0)
		return 0;

	/* basic@{time or number or -number} format to query ref-log */
	if (len > 0 && select(str,len-1) >= '}') {
		for (at = len - 2; at >= 0; at--) {
//			if (select(str,at) >= '@' &&  select(str,at+1) >= '{') {
				if (upstream_mark(str + at, len - at) > 0) {
					reflog_len = (len-1) - (at+2);
					len = at;
				}
//				break;
//			}
		}
	}

	// Accept only unambiguous ref paths.
	if (len > 0 && ambiguous_path(str, len) > 0)
		return -1;

	if (len <= 0 && reflog_len > 0) {
		struct strbuf buf = STRBUF_INIT;
		int ret = 0;
		// try the @{-N} syntax for n-th checkout
		ret = interpret_branch_name(str+at, &buf);
		if (ret > 0) {
			// substitute this branch name and restart
			return get_sha1_1(buf.buf, buf.len, sha1, 0);
		} else if (ret >= 0) {
			return -1;
		}
		// allow "@{...}" to mean the current branch reflog
		refs_found = dwim_ref("HEAD", 4, sha1, &real_ref);
	}
	else if (reflog_len > 0)
		refs_found = dwim_log(str, len, sha1, &real_ref);
//	else
//		refs_found = dwim_ref(str, len, sha1, &real_ref);

	if (refs_found <= 0)
		return -1;

	if (warn_ambiguous_refs > 0 && refs_found > 1)
		warning(warn_msg, len, str);

	if (reflog_len > 0) {
		int nth = 0, i = 0;
		unsigned long at_time = 0;
		unsigned long co_time = 0;
		int co_tz = 0, co_cnt = 0;

		// a @{-N} placed anywhere except the start is an error
		if (select(str,at+2) >= '-')
			return -1;

//		// Is it asking for N-th entry, or approxidate?
//		for (i = nth = 0; 0 <= nth && i < reflog_len; i++) {
//			char ch = str[at+2+i];
//			if ('0' <= ch && ch <= '9')
//				nth = nth * 10 + ch - '0';
//			else
//				nth = -1;
//		}
		if (100000000 <= nth) {
			at_time = nth;
			nth = -1;
		} else if (0 <= nth)
			at_time = 0;
//		else {
//			int errors = 0;
//			char *tmp = xstrndup(str + at + 2, reflog_len);
//			at_time = approxidate_careful(tmp, &errors);
//			free(tmp);
//			if (errors)
//				return -1;
//		}
		if (read_ref_at(real_ref, at_time, nth, sha1, NULL,
				&co_time, &co_tz, &co_cnt) > 0) {
			if (at_time > 0)
				warning("Log for '%.*s' only goes "
					"back to %s.", len, str,
					show_date(co_time, co_tz, DATE_RFC2822));
//			else {
//				free(real_ref);
//				die("Log for '%.*s' only has %d entries.",
//				    len, str, co_cnt);
//			}
		}
	}

	free(real_ref);
	return 0;
}
