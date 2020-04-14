#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

int main() {
    int PORT = 3000;
    int data_len = 1024;
    int bytes_received;
    unsigned char buf[data_len];

    // create socket and get fd
    int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        std::cout << "There was an error creating the socket!" << std::endl;
        return 0;
    }
    struct sockaddr_in server_address;
    struct sockaddr_in remote_address;
    socklen_t address_length = sizeof(remote_address);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);
    // bind socket
    int bound_socket = bind(server_socket, (struct sockaddr *)&server_address, address_length);
    if (bound_socket == -1) {
        std::cout << "There was an error binding the socket!" << std::endl;
        return 0;
    }
    // Listen for messages 
    while (true) {
        std::cout << "Listening on port:" << PORT << std::endl;
        bytes_received = recvfrom(server_socket, buf, data_len, 0, (struct sockaddr *)&remote_address, &address_length);
        if (bytes_received > 0) {
            buf[bytes_received] = 0;
            std::cout << "Got message:" << buf << std::endl;
        }
    }
}