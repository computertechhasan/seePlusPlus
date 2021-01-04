gxx=g++ -O3

all: server client clean

server: server.o
	$(gxx) server.o -o server
client: client.o
	$(gxx) client.o -o client
clean:
	rm *.o