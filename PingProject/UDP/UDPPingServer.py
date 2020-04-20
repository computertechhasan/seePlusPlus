# Hasan Intisar
# hi6, Section 004
import sys
import random
from socket import *
import struct
serverIP = '' # any local IP address
serverPort = 12000
dataLen = 1024
# Create a UDP socket. Notice the use of SOCK_DGRAM for UDP packets
serverSocket = socket(AF_INET, SOCK_DGRAM)
# Assign IP address and port number to socket
serverSocket.bind((serverIP, serverPort))
print('The server is ready to receive on port: ' + str(serverPort))
# loop forever listening for incoming datagram messages
while True:
    # Receive and print the client data from "data" socket
    data, address = serverSocket.recvfrom(dataLen)
    messageVars = struct.unpack("!II", data)
    currMessageType = messageVars[0]
    currSequenceNumber = messageVars[1]
    print("Receive data from client " + address[0] + ", " + str(address[1]) + ": " + data.decode())
    # Echo back to client
    responseRandom = random.randint(1,11)
    if responseRandom < 4:
        print("Message with sequence number " + str(currSequenceNumber) + " was dropped.")
        continue
    print("Sending data to client " + address[0] + ", " + str(address[1]) + ": " + data.decode())
    responseMessage = struct.pack("!II",2,int(currSequenceNumber))
    serverSocket.sendto(responseMessage,address) 