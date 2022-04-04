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
            perror("[-]Error in sending file.");
            exit(EXIT_FAILURE);
        }
        bzero(data, SIZE);
    }
}

int main(){
    char ip[20];
    printf("Enter ip of server:\n");
    scanf("%s", ip);
    printf("You entered: %s\n", ip);

    int port = 34588;
    int e;
    struct sockaddr_in server_addr;
    FILE *file;

    char filename[100];
    printf("Enter path of file to send:\n");
    scanf("%s", filename);
    printf("The path of file: %s\n", filename);

    int sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    printf("[+]Server socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(e == -1) {
        perror("[-]Error in socket");
        exit(EXIT_FAILURE);
    }
    printf("[+]Connected to Server.\n");

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("[-]Error in reading file.");
        exit(EXIT_FAILURE);
    }

    send_file(file, sockfd);
    printf("[+]File data sent successfully.\n");

    printf("[+]Closing the connection.\n");
    close(sockfd);

    return 0;
}