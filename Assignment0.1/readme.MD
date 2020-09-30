Karanjot Singh
2019050

----------------------------------------------------------------

The gcc compiler is used for the C language. There are four steps for successful conversion of a c file to an executable.

 1. pre-processing  - Comments are removed, header files and Macros are expanded

	//command to halt execution after pre processing, a file with .i extension is created: 

	gcc -E hello.c

2.Compilation - Program is converted to assembly language.
	//command to halt execution after compilation, a file with .s extension (assembly file) is created:

	gcc -S hello.c

3. Assembly step- At this step, All code is converted to machine language instructions except function calls.

	//command to halt execution after Assembly, a file with .o extension is created:

	gcc -c HelloWorld.c -o HelloWorld.o

4. Linking: In the final step, All function callls are linked with their definitions,Code for the libraries used is also added to generate a 
	file we can execute. GCC does dynamic linking.

	//command for the final step to create an .out file libraries:
	
	gcc -o hello hello.c 

