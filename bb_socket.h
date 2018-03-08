#ifndef SOCKET_H
#define SOCKET_H

int create_listener_socket(int port, struct sockaddr_in *address);

int create_sending_socket();

#endif //SOCKET_H
