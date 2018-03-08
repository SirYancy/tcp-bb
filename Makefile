CXX = g++
FLAGS += -std=c++11 -g -pthread -O

all: bb_client bb_server

# Object files

bb_socket.o: bb_socket.h bb_socket.cpp
	$(CXX) $(FLAGS) -c bb_socket.cpp

bb_client.o: bb_client.cpp
	$(CXX) $(FLAGS) -c bb_client.cpp

bb_server.o: bb_server.cpp
	$(CXX) $(FLAGS) -c bb_server.cpp

# Executables
bb_client: bb_client.o
	$(CXX) $(FLAGS) -o bb_client bb_client.o

bb_server: bb_server.o bb_socket.o
	$(CXX) $(FLAGS) -o bb_server bb_server.o bb_socket.o

clean:
	$(RM) core *.o bb_server bb_client
