CC = g++
CFLAGS += -std=c++11 -g -O

all: bb_client bb_server

# Object files

bb_client.o: bb_client.cpp
	$(CC) $(CFLAGS) -c bb_client.cpp

bb_server.o: bb_server.cpp
	$(CC) $(CLAGS) -c bb_server.cpp

# Executables
bb_client: bb_client.o
	$(CC) -o bb_client bb_client.o

bb_server: bb_server.o
	$(CC) -o bb_server bb_server.o

clean:
	$(RM) core *.o bb_server bb_client
