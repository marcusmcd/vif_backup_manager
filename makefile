all:
	gcc -Wall -I/usr/local/include/cunit -c main.c
	gcc -o main main.o -lcunit
