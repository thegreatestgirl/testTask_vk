CC = gcc

server: gcc server.c wrapper.c -o server

client: gcc client.c wrapper.c -o client

all: server client

clean:
	rm server
	rm client

rebuild: clean all