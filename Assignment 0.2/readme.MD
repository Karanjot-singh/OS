Karanjot Singh
2019050

----------------------------------------------------------------
Comments alongside code explain the functionality

In the convention for calling a function from C to assembly,
Integer type arguments are received in the rdi, rsi, rdx , rcx,r8 ,r9 registers respectively (x64)

The integers stored in the rax register are returned to the c program.

The assembly file is addded to the C file as a static library,

The following command compiles the assembly to an object file and is later linked with the C file.
 When the definition for function Addition is not found in the C file , The compiler looks in the other files (here, Addition.asm) for the function definition.

nasm -f elf64 Addition.asm -o Addition.o && gcc add.c Addition.o -o sum && ./sum

