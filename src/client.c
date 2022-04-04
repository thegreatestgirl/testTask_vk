#define SIZE 1024
#include "wrapper.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

void send_file(FILE *file, int sockfd){
    int n;
    char data[SIZE] = {0};

    while(fgets(data, SIZE, file) != NULL) {
        if (send(sockfd, data, sizeof(data), 0) == -1) {
            perror("( x)( x) data sending failed");
            exit(EXIT_FAILURE);
        }
        bzero(data, SIZE);
    }
}

int main(){
    char ip[20];
    printf("( |)( |) ip of server, please\n");
    scanf("%s", ip);
    printf("( .)( .) you entered: %s\n", ip);

    int port = 8080;
    int e;
    struct sockaddr_in server_addr;
    FILE *file;

    char filename[100];
    printf("( |)( |) file, which you want to send, please:\n");
    scanf("%s", filename);

    int sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    printf("( .)( .) socket created\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(e == -1) {
        perror("( x)( x) connection failed");
        exit(EXIT_FAILURE);
    }
    printf("( .)( .) connection to server created\n");

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("( x)( x) file reading failed");
        exit(EXIT_FAILURE);
    }

    send_file(file, sockfd);
    printf("( .)( .) data sent\n");

    fclose(file);
    close(sockfd);

    printf("( .)( .) connection closed\n");

    return 0;
}