all: check

check: Q1_c.c
	 nasm -f elf64 Q1.asm -o Q1.o && gcc -nostdlib Q1_c.c Q1.o -o check && ./check
