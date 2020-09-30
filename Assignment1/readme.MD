--------------------------------
Basic shell Implementation in C:
--------------------------------
Karanjot Singh
2019050

-Makefile instructions-

	$ make - To run the shell program
	$ make clean - To delete the object files

-System Calls Used-

	fork() :	fork() creates a new process by duplicating the calling process.
				<unistd.h> , <sys/types.h>

	execvp() :	duplicate the actions of the shell in searching for an executable file
				<unistd.h>

	waitpid() : The wait() function shall suspend execution of the calling thread until status information for one of the terminated child processes of the calling process is available
				<sys/wait.h>

-Shell Input-
	Format: [cmd] [flag] [args]
	
	*In case there are no flags, separate command and argument with two consecutive spaces*



-Shell Commands-
	
	The following commands (and additional flags) were implemented:

	‘echo’		Write arguments to the standard output. 
				flags 	-n do not append a newline
						-e enable interpretation of \a ,\n , \\ etc.

	‘history'	Display or manipulate the history list.
				flags 	-c clear history of current session
						-w writes current history to the history file in files/ history.txt

	'exit’		Exit the Shell

	‘mkdir’		 Create the DIRECTORY(ies), if they do not already exist.

				flags 	-v print a message for each created directory
						-m set file mode (as in chmod)
				Implemented by mkdir()

	‘ls'		List information about the FILEs 
				flags 	-A do not list implied . and .. 
						-U do not sort
				Implemented by opendir() , closedir() functions in <dirent.h>

	'rm’		Remove (unlink) the FILE(s).
				flags 	-i prompt before every removal
						-d remove empty directories
				Implemented by opendir() , closedir() functions in <dirent.h>
						
	'cat’		Concatenate FILE(s) to standard output.
				flags 	-n number all output lines
						-E display $ at end of each line

	‘date’		Display the current time in the given FORMAT
				flags 	-u print Coordinated Universal Time (UTC)
						-R output date and time in RFC 5322 format.
				Implemented by functions in <time.h>

	'pwd’		Print the name of the current working directory.
				flags 	-L  print the value of $PWD if it names the current working directory
						--help
	‘cd’
				flags 	-P use the physical directory structure without following symbolic links:
						-e if current working directory cannot be determined successfully, exit with a non-zero status
				Implemented by opendir() , closedir() functions in <dirent.h>



-Corner Cases- 
	Errors if any, during  fork(), execvp() system calls are returned with prompt by perror() without terminating the program
	Errors if any, during  shell commands are returned with prompt by perror() without terminating the program. Eg: no such directory
	Errors if any, during read/write returned with prompt by perror() without terminating the program
	Invalid commands don't break the program
	Invalid Flags prompt the user to see --help

-Assumptions-
	Only single Arguments are passed in all functions
	user has administrator/root access

-Test Cases-
	Included in files/Testcase.txt

*content referenced from man pages
Implemented as Assignment 1 in CSE- Operating Systems course
