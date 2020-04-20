#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

int main() {
    int data_len = 1024;
    int PORT = 3000;
    char* message = "I worked! Now lets try something really long to see if it still works cuz there is a limit to this";

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    char buffer[data_len] = {0};
    inet_pton(AF_INET, "127.0.0.1", &(server_address.sin_addr));

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cout << "There was an error creating the socket!" << std::endl;
        return 0;
    }

    int connected_socket = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connected_socket == -1) {
        std::cout << "There was an error connecting to the server!" << std::endl;
        return 0;
    }
    int send_message = send(client_socket, message, strlen(message), 0);
    if (send_message == -1) {
        std::cout << "There was an error sending!" << std::endl;
        return 0;
    }
    else {
        std::cout << "Client sent the message:" << message << std::endl;
        // return 0;
    }
    int server_response = read(client_socket, buffer, data_len);
    std::cout << "Server responded:" << buffer << std::endl;
} 