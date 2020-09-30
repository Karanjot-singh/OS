--------------------------------------------------------------------------------------------
	Format: [cmd] [flag] [args]
	
	*In case there are no flags, separate command and argument with two consecutive spaces*
--------------------------------------------------------------------------------------------
-Shell Commands-


	‘echo’	
				flags 	-n do not append a newline
						-e enable interpretation of \a ,\n , \\ etc.

	‘history'
				flags 	-c clear history of current session
						-w writes current history to the history file in files/ history.txt

	'exit’		Exit the Shell

	‘mkdir’		

				flags 	-v print a message for each created directory
						-m set file mode (as in chmod)

	‘ls'
				flags 	-A do not list implied . and .. 
						-U do not sort

	'rm’
				flags 	-i prompt before every removal
						-d remove empty directories
						
	'cat’		Concatenate FILE(s) to standard output.
				flags 	-n number all output lines
						-E display $ at end of each line

	‘date’		Display the current time in the given FORMAT
				flags 	-u print Coordinated Universal Time (UTC)
						-R output date and time in RFC 5322 format.

	'pwd’		Print the name of the current working directory.
				flags 	-L  print the value of $PWD if it names the current working directory
						--help
	‘cd’
				flags 	-P use the physical directory structure without following symbolic links:
						-e if current working directory cannot be determined successfully, exit with a non-zero status