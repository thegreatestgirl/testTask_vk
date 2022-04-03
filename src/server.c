#include "wrapper.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET - IPv4
    // SOCK_STREAM - duplex 
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;

    int port;
    scanf("%d", &port);
    printf("%d\n", port);

    adr.sin_port = htons(port);
    Bind(server, (struct sockaddr *) &adr, sizeof adr);
    Listen(server, 5);
    socklen_t adrlen = sizeof adr;
    int fd = Accept(server, (struct sockaddr *) &adr, &adrlen);
    ssize_t nread;
    char buf[256];
    nread = read(fd, buf, 256);
    if (nread == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    if (nread == 0) {
        printf("EOF occured\n");
    }
    write(STDOUT_FILENO, buf, nread);
    write(fd, buf, nread);

    sleep(15);

    close(fd);
    close(server);
    return 0;
}
