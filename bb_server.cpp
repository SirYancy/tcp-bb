// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "bb_socket.h"

#define PORT 8080

int server_fd;
struct sockaddr_in *address;
int addrlen;
int live = 1;

void *client_listen_thread(void *client_args);

int main(int argc, char const *argv[])
{
    address = (sockaddr_in*)malloc(sizeof(sockaddr_in));
    addrlen = sizeof(address);
    char const *hello = "Hello from server";
    pthread_t client_thread;

    server_fd = create_listener_socket(PORT, address);

    pthread_create(&client_thread, NULL, client_listen_thread, NULL);

    while(live){}

    return 0;
}

void *client_listen_thread(void *client_args)
{
    int client_socket;
    char buffer[1024] = {0};
    int valread;
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, 
                           (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(client_socket , buffer, 1024);
        printf("%s\n",buffer );
        send(client_socket , buffer , strlen(buffer) , 0 );
        printf("Echo Sent\n");
    }
}
