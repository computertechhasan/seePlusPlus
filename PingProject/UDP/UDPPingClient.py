# Hasan Intisar
# hi6, Section 004
import sys, time
from socket import *
from datetime import datetime
import struct
# Get the server hostname, port and data length as command line arguments
argv = sys.argv
host = argv[1]
port = argv[2]
TOTAL_PACKETS_SENT = 10
RTTArray = []
packetsRecieved = 0
# Command line argument is a string, change the port and count into integer
port = int(port)
# Create UDP client socket. Note the use of SOCK_DGRAM, DGRAM = UDP STREAM = TCP
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(1)
print("The server at IP address " + str(host) + " and port " + str(port) + " will be pinged. \n")
for packetNumber in range(1,TOTAL_PACKETS_SENT+1):
    try:
        # Sending data to server
        data = str(packetNumber)
        currentMessage = struct.pack("!II", 1, int(data))
        print("Sending packet number " + data)
        startTime = datetime.now()
        clientSocket.sendto(currentMessage,(host, port))
        # Receive the server response
        dataEcho, address = clientSocket.recvfrom(1024)
        responseVars = struct.unpack("!II", dataEcho)
        currMessageType = responseVars[0]
        currSequenceNumber = responseVars[1]
        endTime = datetime.now()
        RTT = endTime - startTime
        RTTFloatMS = (RTT.total_seconds()) * 1000
        RTTArray.append(RTTFloatMS)
        # Display the server response as an output
        #Close the client socket
        print("Receive packet number " + str(currSequenceNumber))
        print("The RTT was " + str(RTTFloatMS) + " ms." + "\n")
        packetsRecieved += 1
    except timeout: # Originally I was using Socket.timeout, this helped me solve that problem https://stackoverflow.com/questions/11865685/handling-a-timeout-error-in-python-sockets/11865993
        print("The message timed out for packet " + data)
        continue
lossPercentage = (((TOTAL_PACKETS_SENT-packetsRecieved) / TOTAL_PACKETS_SENT)* 100)
print(str(TOTAL_PACKETS_SENT) + " packets were sent. " + str(packetsRecieved) + " packets were recieved. " + str(lossPercentage) + "% of packets were lost")
minRTT = min(RTTArray)
maxRTT = max(RTTArray)
averageRTT = sum(RTTArray) / float(len(RTTArray))
print("The minimum RTT was " + str(minRTT) + "ms.")
print("The maximum RTT was " + str(maxRTT) + "ms.")
print("The average RTT was " + str(averageRTT) + "ms.")
clientSocket.close() 
