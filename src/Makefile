CC = gcc

# server: server.o wrapper.o
# 	$(CC) server.o wrapper.o -o server

# server.o: server.c wrapper.c
# 	$(CC) server.c wrapper.c -o server.o

# client: client.o wrapper.o
# 	$(CC) client.o wrapper.o -o client

# client.o: client.c wrapper.c
# 	$(CC) client.c wrapper.c -o client.o

# wrapper.o: wrapper.c
# 	$(CC) wrapper.c -o wrapper.o

all: server client

server: server.c wrapper.c
	$(CC) server.c wrapper.c -o server

client: client.c wrapper.c
	$(CC) client.c wrapper.c -o client

clean:
	rm -rf *.o
	rm -rf server
	rm -rf client

rebuild: clean all