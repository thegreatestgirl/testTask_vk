#define SIZE 1024
#include "wrapper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

void write_file(int sockfd, char* directory){
    char *filename = "new.txt";
    char check[100] = "/";

    if (strcmp(directory, check) == 0) {
        directory = filename;
        printf("( .)( .) full path to file is: %s\n", directory);
    } else {
        strcat(directory, "/");
        strcat(directory, filename);
        printf("( .)( .) full path to file is: %s\n", directory);
    }

    int n;
    FILE *file;
    char buffer[SIZE];

    file = fopen(directory, "w+");

    while (1) {
        n = recv(sockfd, buffer, SIZE, 0);
        if (n <= 0){
            break;
            return;
        }
        fprintf(file, "%s", buffer);
        bzero(buffer, SIZE);
    }
    fclose(file);
}

int main(){
    char *ip = "0.0.0.0";
    int e, port;
    printf("( |)( |) port for listening, please\n");
    scanf("%d", &port);
    printf("( .)( .) you entered: %d\n", port);

    char directory[100];
    printf("( |)( |) directory to save file, please\n");
    scanf("%s", directory);
    printf("( .)( .) you entered: %s\n", directory);
    

    int sockfd, new_sock;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[SIZE];

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    printf("( .)( .) socket created\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(e < 0) {
        perror("( x)( x) bind failed");
        exit(EXIT_FAILURE);
    }
    printf("( .)( .) bind created\n");

    Listen(sockfd, 10);
    printf("( .)( .) ....listening.... (. )(. )\n");

    addr_size = sizeof(new_addr);
    new_sock = Accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);

    write_file(new_sock, directory);
    printf("( .)( .) data saved\n");

    sleep(5);
    close(new_sock);
    close(sockfd);
    printf("( .)( .) connection closed\n");
    return 0;
}
