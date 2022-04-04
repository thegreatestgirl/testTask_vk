CC = gcc

# server: gcc server.c wrapper.c -o server

server.o: server.c
	$(CC) -c server.c

# client: gcc client.c wrapper.c -o client

client.o: client.c
	$(CC) -c client.c

server: server.o
	$(CC) -o server.o

client: client.o
	$(CC) -o client.o

all: server client

clean:
	rm -rf *.o

rebuild: clean all