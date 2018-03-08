#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int create_listener_socket(int port, struct sockaddr_in *address)
{
    int server_fd;

    int opt = 1;

    // Creating socket descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        return -1;
    }

    // Attaching socket to port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        return -1;
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons( port );

    // Binding socket to port
    if (bind(server_fd, (struct sockaddr *)address, sizeof(*address))<0)
    {
        perror("bind failed");
        return -1;
    }

    return server_fd;

}

int create_sending_socket()
{
    int receive_fd;

}
