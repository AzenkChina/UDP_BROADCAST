#comm socket for C


.PHONY: all clean

all:TEST_C
	gcc comm_socket.o TEST_C.o -o TEST_C

TEST_C:TEST_C.o comm_socket.o
	gcc -c comm_socket.c -o comm_socket.o -O3 -std=c99
	gcc -c TEST_C.c -o TEST_C.o -O3 -std=c99

clean:
	rm *.o
