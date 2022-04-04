CC:=gcc

server: $(CC) server.c wrapper.c -o server

client: $(CC) client.c wrapper.c -o client

all: server client

clean:
	rm server
	rm client

rebuild: clean all