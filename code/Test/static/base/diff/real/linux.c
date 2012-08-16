#define RPCBIND_MAXUADDRLEN  (42)
typedef unsigned int size_t;

size_t rpc_uaddr2sockaddr (const size_t uaddr_len) {
  char buf[ RPCBIND_MAXUADDRLEN ];

  if ( uaddr_len > sizeof ( buf ))
    return 0;

  buf [ uaddr_len ] = '\n';
  buf [ uaddr_len + 1] = '\0';

}

