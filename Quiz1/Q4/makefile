all: long_add

long_add: extended_add
	nasm -f elf32 P4_1.asm -o P4_1.o && gcc -m32 P4.c P4_1.o -o long_add
extended_add:
	nasm -f elf64 P4_2.asm -o P4_2.o && gcc P4.c P4_2.o -o extended_add
	
