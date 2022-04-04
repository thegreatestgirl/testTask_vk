#ifndef SRC_WRAPPER_H_
#define SRC_WRAPPER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int Socket(int domain, int type, int protocol);

void Listen(int sockfd, int backlog);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

#endif  // SRC_WRAPPER_H_