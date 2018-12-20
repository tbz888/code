from socket import *

clientSocket = socket(AF_INET, SOCK_DGRAM)

for x in xrange(1,5):
    # sender
    message = raw_input('Input lowercase sentence:')
    clientSocket.sendto(message, ('127.0.0.1', 2015))
    
    # receiver
    modifiedMessage, serverAddress = clientSocket.recvfrom(2333)
    print "Response: " + modifiedMessage

clientSocket.close()
