#include "wrapper.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(34588);

    FILE *file;
    char *filename = "test.txt";


    char ipServer[20];
    scanf("%s", ipServer);
    printf("%s\n", ipServer);

    Inet_pton(AF_INET, ipServer, &adr.sin_addr);
    Connect(fd, (struct sockaddr *) &adr, sizeof adr);
    write(fd, "Hi there\n", 9);
    char buf[256];
    ssize_t nread;
    nread = read(fd, buf, 256);
    if (nread == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    if (nread == 0) {
        printf("EOF occured\n");
    }
    write(STDOUT_FILENO, buf, nread);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("file reading failed");
        exit(EXIT_FAILURE);
    }
    printf("before sending\n");
    // sending(file, fd);

    // char data[256] = {0};
    printf("before while");

    char data[256] = {0};
    while (!feof(file)) {
        if (send(fd, data, sizeof(data), 0) == -1) {
            perror("file sending failed");
            exit(EXIT_FAILURE);
        }
        // bzero(data, 256);
        memset(data, 0, 256);
    }
    printf("after");

    printf("send successfully\n");
    // fclose(file);

    sleep(10);
    close(fd);
    return 0;
}
