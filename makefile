all: util buildtests main

main:
	gcc -Wall -I/usr/include/cunit -c main.c
	gcc -o main main.o util.o -lcunit
util:
	gcc -Wall -I/usr/include/cunit -c util.c
	#gcc -o util util.o -lcunit
buildtests:
	gcc -Wall -I/usr/include/cunit -c run_tests.c
	gcc -o run_tests run_tests.o util.o -lcunit
test:
	./run_tests
