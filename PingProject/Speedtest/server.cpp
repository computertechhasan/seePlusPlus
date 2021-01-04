#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

int main() {
    int PORT = 3000;
    // data to send in bytes
    int kb = 1024;
    int data_len = 7*kb*kb;
    int bytes_received;
    unsigned char buf[data_len];
    const char * server_message = "hi i am the server";

    // create socket and get fd
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
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
    std::cout << "Listening on port:" << PORT << std::endl;
    int listening_socket = listen(server_socket, 5);
    if (listening_socket == -1) {
        std::cout << "There was an error making the socket listen!" << std::endl;
        return 0;
    }
   
    int read_socket = accept(server_socket, (struct sockaddr *)&remote_address, &address_length);
    if (read_socket < 0) {
        std::cout << "There was a handshake error!" << std::endl;
        return 0;
    }

    while (true) {
        // bytes_received = recvfrom(server_socket, buf, data_len, 0, (struct sockaddr *)&remote_address, &address_length);
        bytes_received = read(read_socket, buf, data_len);
        if (bytes_received > 0) {
            std::cout << "got" << bytes_received << "bytes" << std::endl;
            buf[bytes_received] = 0;
            std::cout << "Got message:" << buf << std::endl;
        }
        send(read_socket, server_message, strlen(server_message), 0);
        std::cout << "server responded with" << server_message << std::endl;
    }
}