from socket import *

# sender
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(("", 2015))  

print "The server is ready to receive..."
while True:
    message, clientAddress = serverSocket.recvfrom(2333)
    print "From: ",clientAddress
    print "--Message: " + message
    if message == "halt server":
        break
    modifiedMessage = message.upper()
    serverSocket.sendto(modifiedMessage, clientAddress)

serverSocket.close()
