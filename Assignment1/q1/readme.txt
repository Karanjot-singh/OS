--------------------------------
Assignment 1   Q1
--------------------------------
Karanjot Singh
2019050

-Makefile instructions-

	$ make - To run the shell program
	$ make clean - To delete the intermediate files .i .o .s , etc..

-System Calls Used-

	open():		The open() function shall establish the connection between a file and a file descriptor. 
				It shall create an open file description that refers to a file and a file descriptor that refers to that open file description.
				<sys/stat.h>, <fcntl.h>

	read():		 read() attempts to read up to count bytes from file descriptor fd
       			into the buffer starting at buf.
       			<unistd.h>

	exit():		The exit() function causes normal process termination and the least
       			significant byte of status (i.e., status & 0xFF) is returned to the
       			parent. 
       			<stdlib.h>

	fork() :	fork() creates a new process by duplicating the calling process.
				<unistd.h> , <sys/types.h>

	waitpid() : The wait() function shall suspend execution of the calling thread until status information for one of the terminated child processes of the calling process is available
				<sys/wait.h>

-Functioning of Code
	At the beginning of the program, it is forked into a parent and a child process. The parent process waits for the child process to exit before proceeding further. This is done by waitpid(-1, &status, 0) . The child process is used to read the csv and output the average marks for all Section A and after the child process is finished, The arent process does the same for Section B students.

	How is the file read?
	In both the processes, The file is accessed by the open() system call and opened in the read only mode with O_RDONLY.Next The read sys call is used to 
	read the contents of the file into a character array (content). Since the given file is a CSV , First each row is extracted using strncat() function to extract the row each time a new line character is extracted. Next, Each row is tokenised according to columns separated by commas by strtok()

	After this, Content is processed and printf() is used to show the output

	

-Corner Cases- 
	Errors if any, during  fork() system calls and waitpid() are returned with prompt by perror() without terminating the program
	Errors if any, during read/write returned with prompt by perror() without terminating the program
	Invalid commands don't break the program
	Invalid Flags prompt the user to see --help

Implemented as Assignment 1 in CSE- Operating Systems course
*content referenced from man pages