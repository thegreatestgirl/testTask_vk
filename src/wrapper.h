#ifndef SRC_WRAPPER_H_
#define SRC_WRAPPER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int Socket(int domain, int type, int protocol);

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void Listen(int sockfd, int backlog);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void Inet_pton(int af, const char *src, void *dst);

#endif  // SRC_WRAPPER_H_