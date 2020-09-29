When you run history -c you clear the complete history list in memory, but again this does not affect the history file on the disk.

Running history -w writes your current history list in memory to the history file on disk. It does not append new entries but overwrites the complete file.

https://askubuntu.com/questions/832335/whats-the-difference-between-history-w-and-the-action-of-closing-a-shell-ses

Available commands:
‘cd’, ‘echo’, ‘history’, 

‘pwd’ and ‘exit’
‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’

execvp
In the child process, we want to run the command given by the user. So, we use one of the many variants of the exec system call, execvp. The different variants of exec do slightly different things. Some take a variable number of string arguments. Others take a list of strings. Still others let you specify the environment that the process runs with. This particular variant expects a program name and an array (also called a vector, hence the ‘v’) of string arguments (the first one has to be the program name). The ‘p’ means that instead of providing the full file path of the program to run, we’re going to give its name, and let the operating system search for the program in the path.