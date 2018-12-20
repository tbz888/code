from socket import *
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(("", 12000))
serverSocket.listen(1)
print 'The server is ready to receive...'

while True:
    connectionSocket, addr = serverSocket.accept()
    sentence = connectionSocket.recv(1024)
    print "From: ", addr
    print "--Message: ", sentence
    if sentence == "halt server":
        break
    capitalizedSentence = sentence.upper()
    connectionSocket.send(capitalizedSentence)

connectionSocket.close()
