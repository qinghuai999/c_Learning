CC = gcc
CFLAGS = -Wall -pedantic -std=gnu99 -Wextra

.DEFAULT_GOAL := all
.PHONY: all clean

all: client server database

client: client.o shared.o
	$(CC) $(CFLAGS) client.o shared.o -o client

server: server.o shared.o
	$(CC) $(CFLAGS) server.o shared.o -o server

database: database.o shared.o
	$(CC) $(CFLAGS) database.o shared.o -o database


client.o: client.c shared.h
	$(CC) $(CFLAGS) -c client.c -o client.o

server.o: server.c shared.h
	$(CC) $(CFLAGS) -c server.c -o server.o

database.o: database.c shared.h
	$(CC) $(CFLAGS) -c database.c -o database.o

shared.o: shared.c shared.h
	$(CC) $(CFLAGS) -c shared.c -o shared.o

clean:
	rm -f *.o client server database
