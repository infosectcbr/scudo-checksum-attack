CC=clang
CFLAGS=-fsanitize=scudo -Wall -g -no-pie

all: scudo-checksum scudo-leak

scudo-checksum: scudo-checksum.cpp
	$(CC) $(CFLAGS) scudo-checksum.cpp -o scudo-checksum

scudo-leak: scudo-leak.cpp
	$(CC) $(CFLAGS) scudo-leak.cpp -o scudo-leak
