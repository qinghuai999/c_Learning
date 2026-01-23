CC = gcc
CFLAGS = -Wall -pedantic -std=gnu99 -Wextra
INCLUDES = -Iinclude
LDFLAGS = -Llib -lphraseC

.DEFAULT_GOAL := main
.PHONY: clean lib

# ===== Build shared library =====
lib/libphraseC.so: phraseC.c include/phraseC.h
	mkdir -p lib
	$(CC) -shared -fPIC $(CFLAGS) $(INCLUDES) phraseC.c -o lib/libphraseC.so

# ===== Object files =====
main.o: main.c include/phraseC.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c -o main.o

phraseA.o: phraseA.c
	$(CC) $(CFLAGS) -c phraseA.c -o phraseA.o

phraseB.o: phraseB.c
	$(CC) $(CFLAGS) -c phraseB.c -o phraseB.o

# ===== Final executable =====
main: lib/libphraseC.so main.o phraseA.o phraseB.o
	$(CC) $(CFLAGS) main.o phraseA.o phraseB.o $(LDFLAGS) -o main

# ===== Clean =====
clean:
	rm -f main *.o lib/libphraseC.so