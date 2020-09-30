all: hello

hello: hello.o
	 gcc hello.c -o hello

hello.o: hello.s
	 gcc -c hello.c -o hello.o

hello.s: hello.i
	 gcc -S hello.c

hello.i: hello.c
	 gcc -E hello.c > hello.i
