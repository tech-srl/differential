#define RPCBIND_MAXUADDRLEN  	(42)
#define NULL 			(0)
#define unlikely(c)		(c)

typedef enum {AF_INET, AF_INET6} family;

typedef int size_t;

struct net {
};

struct sockaddr {
	family sa_family;
};

struct sockaddr_in {
	int sin_port;
};

struct sockaddr_in6 {
	int sin6_port;
};

extern memcpy(...);
extern char * strrchr(...);
extern strlen(...);
extern strict_strtoul(...);
extern int htons(...);
extern rpc_pton(...);

size_t rpc_uaddr2sockaddr(struct net *net, const char *uaddr,
			  const size_t uaddr_len, struct sockaddr *sap,
			  const size_t salen)
{
	char *c, buf[RPCBIND_MAXUADDRLEN];
	unsigned long portlo, porthi;
	unsigned short port;

	if (uaddr_len > RPCBIND_MAXUADDRLEN)
		return 0;

	memcpy(buf, uaddr, uaddr_len);

	buf[uaddr_len] = '\0';
	c = strrchr(buf, '.');

	if (unlikely(c == NULL))
		return 0;
	if (unlikely(strict_strtoul(c + 1, 10, &portlo) != 0))
		return 0;
	if (unlikely(portlo > 255))
		return 0;

	*c = '\0';
	c = strrchr(buf, '.');
	if (unlikely(c == NULL))
		return 0;
	if (unlikely(strict_strtoul(c + 1, 10, &porthi) != 0))
		return 0;
	if (unlikely(porthi > 255))
		return 0;

	port = (unsigned short)((porthi << 8) | portlo);

	*c = '\0';
	if (rpc_pton(net, buf, strlen(buf), sap, salen) == 0)
		return 0;

	if (sap->sa_family == AF_INET) {
		((struct sockaddr_in *)sap)->sin_port = htons(port);
		return sizeof(struct sockaddr_in);
	} else if (sap->sa_family == AF_INET6) {
		((struct sockaddr_in6 *)sap)->sin6_port = htons(port);
		return sizeof(struct sockaddr_in6);
	}

	return 0;
}
