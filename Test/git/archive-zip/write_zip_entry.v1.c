#define NULL 0
#define ZIP_UTF8 1
#define OBJ_BLOB 2
#define ZIP_STREAM 3
#define ZIP_EXTRA_MTIME_PAYLOAD_SIZE 4
#define ZIP_DIR_HEADER_SIZE 5
#define ZIP_EXTRA_MTIME_SIZE 6
#define ZIP_DIRECTORY_MIN_SIZE 7
#define ZIP_LOCAL_HEADER_SIZE 8
#define STREAM_BUFFER_SIZE 9
#define ZIP_DATA_DESC_SIZE 10
#define Z_OK 11
#define Z_FINISH 12
#define Z_STREAM_END 13

typedef int size_t;
typedef int ssize_t;

struct archiver_args {
	int compression_level;
	int convert;
	int time;
};
struct zip_local_header {
	int magic;
	int creator_version;
	int version; int flags;
	int compression_method;
	int mtime;
	int mdate;
	int filename_length;
	int extra_length;
	int comment_length;
	int disk;
	int attr1;
	int attr2;
	int offset;

};
struct zip_dir_header {
	int magic;
	int creator_version;
	int version; int flags;
	int compression_method;
	int mtime;
	int mdate;
	int filename_length;
	int extra_length;
	int comment_length;
	int disk;
	int attr1;
	int attr2;
	int offset;

};
struct zip_extra_mtime {
	int magic;
	int extra_size;
	int * flags;
	int mtime;
};

typedef struct {
	int next_out;
	int avail_out;
	int next_in;
	int avail_in;

} git_zstream;

extern int crc32(...);
extern int has_only_ascii(...);
extern int is_utf8(...);
extern int error(...);
extern int warning(...);
extern int sha1_to_hex(...);
extern int S_ISDIR(...);
extern int S_ISGITLINK(...);
extern int S_ISREG(...);
extern int S_ISLNK(...);
extern int sha1_object_info(...);
extern int open_istream(...);
extern int sha1_file_to_archive(...);
extern int zlib_deflate(...);
extern int copy_le16(...);
extern int copy_le32(...);
extern int xrealloc(...);
extern int set_zip_dir_data_desc(...);
extern int write_or_die(...);
extern int git_deflate(...);
extern int memcpy(...);
extern int free(...);
extern int memset(...);
extern int git_deflate_init(...);
extern int set_zip_header_data_desc(...);
extern int read_istream(...);
extern int close_istream(...);
extern int write_zip_data_desc(...);
extern int die(...);
extern int git_deflate_end(...);


static int write_zip_entry(struct archiver_args *args,
		const unsigned char *sha1,
		const char *path, size_t pathlen,
		unsigned int mode, int big_file_threshold,
		int zip_dir_size, int zip_dir_offset, int zip_dir,
		int zip_time, int zip_date, int zip_offset, int zip_dir_entries)
{
	struct zip_local_header header;
	struct zip_dir_header dirent;
	struct zip_extra_mtime extra;
	unsigned long attr2 = 0;
	unsigned long compressed_size = 0;
	unsigned long crc = 0;
	unsigned long direntsize = 0;
	int method = 0;
	int out = 0;
	int deflated = 0;
	int buffer = 0;
	int stream = 0;
	unsigned long flags = 0;
	unsigned long size = 0;

	crc = crc32(0, NULL, 0);

	if (!has_only_ascii(path)) {
		if (is_utf8(path))
			flags |= ZIP_UTF8;
		else
			warning("Path is not valid UTF-8: %s", path);
	}

	if (pathlen > 0xffff) {
		return error("path too long (%d chars, SHA1: %s): %s",
				(int)pathlen, sha1_to_hex(sha1), path);
	}

	if (S_ISDIR(mode) || S_ISGITLINK(mode)) {
		method = 0;
		attr2 = 16;
		out = NULL;
		size = 0;
		compressed_size = 0;
		buffer = NULL;
	} else if (S_ISREG(mode) || S_ISLNK(mode)) {
		int type = sha1_object_info(sha1, &size);

		method = 0;
		attr2 = S_ISLNK(mode) ? ((mode | 0777) << 16) :
				(mode & 0111) ? ((mode) << 16) : 0;
		if (S_ISREG(mode) && args->compression_level != 0 && size > 0)
			method = 8;
		compressed_size = size;

		if (S_ISREG(mode) && type == OBJ_BLOB && !args->convert &&
				size > big_file_threshold) {
			stream = open_istream(sha1, &type, &size, NULL);
			if (!stream)
				return error("cannot stream blob %s",
						sha1_to_hex(sha1));
			flags |= ZIP_STREAM;
			out = buffer = NULL;
		} else {
			buffer = sha1_file_to_archive(args, path, sha1, mode,
					&type, &size);
			if (!buffer)
				return error("cannot read %s",
						sha1_to_hex(sha1));
			crc = crc32(crc, buffer, size);
			out = buffer;
		}
	} else {
		return error("unsupported file mode: 0%o (SHA1: %s)", mode,
				sha1_to_hex(sha1));
	}

//	if (buffer && method == 8) {
//		deflated = zlib_deflate(buffer, size, args->compression_level,
//				&compressed_size);
//		if (deflated && compressed_size - 6 < size) {
//			/* ZLIB --> raw compressed data (see RFC 1950) */
//			/* CMF and FLG ... */
//			out = deflated + 2;
//			compressed_size -= 6;	/* ... and ADLER32 */
//		} else {
//			method = 0;
//			compressed_size = size;
//		}
//	}
//
//	copy_le16(extra.magic, 0x5455);
//	copy_le16(extra.extra_size, ZIP_EXTRA_MTIME_PAYLOAD_SIZE);
//	extra.flags[0] = 1;	/* just mtime */
//	copy_le32(extra.mtime, args->time);
//
//	/* make sure we have enough free space in the dictionary */
//	direntsize = ZIP_DIR_HEADER_SIZE + pathlen + ZIP_EXTRA_MTIME_SIZE;
//	while (zip_dir_size < zip_dir_offset + direntsize) {
//		zip_dir_size += ZIP_DIRECTORY_MIN_SIZE;
//		zip_dir = xrealloc(zip_dir, zip_dir_size);
//	}
//
//	copy_le32(dirent.magic, 0x02014b50);
//	copy_le16(dirent.creator_version,
//			S_ISLNK(mode) || (S_ISREG(mode) && (mode & 0111)) ? 0x0317 : 0);
//	copy_le16(dirent.version, 10);
//	copy_le16(dirent.flags, flags);
//	copy_le16(dirent.compression_method, method);
//	copy_le16(dirent.mtime, zip_time);
//	copy_le16(dirent.mdate, zip_date);
//	set_zip_dir_data_desc(&dirent, size, compressed_size, crc);
//	copy_le16(dirent.filename_length, pathlen);
//	copy_le16(dirent.extra_length, ZIP_EXTRA_MTIME_SIZE);
//	copy_le16(dirent.comment_length, 0);
//	copy_le16(dirent.disk, 0);
//	copy_le16(dirent.attr1, 0);
//	copy_le32(dirent.attr2, attr2);
//	copy_le32(dirent.offset, zip_offset);
//
//	copy_le32(header.magic, 0x04034b50);
//	copy_le16(header.version, 10);
//	copy_le16(header.flags, flags);
//	copy_le16(header.compression_method, method);
//	copy_le16(header.mtime, zip_time);
//	copy_le16(header.mdate, zip_date);
//	set_zip_header_data_desc(&header, size, compressed_size, crc);
//	copy_le16(header.filename_length, pathlen);
//	copy_le16(header.extra_length, ZIP_EXTRA_MTIME_SIZE);
//	write_or_die(1, &header, ZIP_LOCAL_HEADER_SIZE);
//	zip_offset += ZIP_LOCAL_HEADER_SIZE;
//	write_or_die(1, path, pathlen);
//	zip_offset += pathlen;
//	write_or_die(1, &extra, ZIP_EXTRA_MTIME_SIZE);
//	zip_offset += ZIP_EXTRA_MTIME_SIZE;
//	if (stream && method == 0) {
//		unsigned char buf[STREAM_BUFFER_SIZE];
//		ssize_t readlen = 0;
//
//		for (;;) {
//			readlen = read_istream(stream, buf, sizeof(buf));
//			if (readlen <= 0)
//				break;
//			crc = crc32(crc, buf, readlen);
//			write_or_die(1, buf, readlen);
//		}
//		close_istream(stream);
//		if (readlen)
//			return readlen;
//
//		compressed_size = size;
//		zip_offset += compressed_size;
//
//		write_zip_data_desc(size, compressed_size, crc);
//		zip_offset += ZIP_DATA_DESC_SIZE;
//
//		set_zip_dir_data_desc(&dirent, size, compressed_size, crc);
//	} else if (stream && method == 8) {
//		int buf;
//		ssize_t readlen;
//		git_zstream zstream;
//		int result;
//		size_t out_len;
//		int compressed;
//
//		memset(&zstream, 0, sizeof(zstream));
//		git_deflate_init(&zstream, args->compression_level);
//
//		compressed_size = 0;
//		zstream.next_out = compressed;
//		zstream.avail_out = sizeof(compressed);
//
//		for (;;) {
//			readlen = read_istream(stream, buf, sizeof(buf));
//			if (readlen <= 0)
//				break;
//			crc = crc32(crc, buf, readlen);
//
//			zstream.next_in = buf;
//			zstream.avail_in = readlen;
//			result = git_deflate(&zstream, 0);
//			if (result != Z_OK)
//				die("deflate error (%d)", result);
//			out = compressed;
//			if (!compressed_size)
//				out += 2;
//			out_len = zstream.next_out - out;
//
//			if (out_len > 0) {
//				write_or_die(1, out, out_len);
//				compressed_size += out_len;
//				zstream.next_out = compressed;
//				zstream.avail_out = sizeof(compressed);
//			}
//
//		}
//		close_istream(stream);
//		if (readlen)
//			return readlen;
//
//		zstream.next_in = buf;
//		zstream.avail_in = 0;
//		result = git_deflate(&zstream, Z_FINISH);
//		if (result != Z_STREAM_END)
//			die("deflate error (%d)", result);
//
//		git_deflate_end(&zstream);
//		out = compressed;
//		if (!compressed_size)
//			out += 2;
//		out_len = zstream.next_out - out - 4;
//		write_or_die(1, out, out_len);
//		compressed_size += out_len;
//		zip_offset += compressed_size;
//
//		write_zip_data_desc(size, compressed_size, crc);
//		zip_offset += ZIP_DATA_DESC_SIZE;
//
//		set_zip_dir_data_desc(&dirent, size, compressed_size, crc);
//	} else if (compressed_size > 0) {
//		write_or_die(1, out, compressed_size);
//		zip_offset += compressed_size;
//	}
//
//	free(deflated);
//	free(buffer);
//
//	memcpy(zip_dir + zip_dir_offset, &dirent, ZIP_DIR_HEADER_SIZE);
//	zip_dir_offset += ZIP_DIR_HEADER_SIZE;
//	memcpy(zip_dir + zip_dir_offset, path, pathlen);
//	zip_dir_offset += pathlen;
//	memcpy(zip_dir + zip_dir_offset, &extra, ZIP_EXTRA_MTIME_SIZE);
//	zip_dir_offset += ZIP_EXTRA_MTIME_SIZE;
//	zip_dir_entries++;

	return 0;
}


