#comm socket for C


.PHONY: all clean

all:TEST_CPP
	g++ comm_socket.o TEST_CPP.o -o TEST_CPP

TEST_CPP:TEST_CPP.o comm_socket.o
	g++ -c comm_socket.cpp -o comm_socket.o -O3
	g++ -c TEST_CPP.cpp -o TEST_CPP.o -O3

clean:
	rm *.o
