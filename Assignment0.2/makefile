all: hello

hello: add.c
	 nasm -f elf64 Addition.asm -o Addition.o && gcc add.c Addition.o -o sum && ./sum
