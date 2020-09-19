all: check

check: greater
	 nasm -f elf64 Q1.asm -o Q1.o && gcc --entry=_start -nostdlib Q1_c.c Q1.o -o startCheckGreater
greater:
	 nasm -f elf64 Q1.asm -o Q1.o && gcc --entry=main -nostdlib Q1_c.c Q1.o -o mainCheckGreater