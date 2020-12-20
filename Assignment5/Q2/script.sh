#!/bin/bash
# Shell script to open terminals
# and execute a separate command in each

# Commands to run (one per terminal) Space seperated
cmds=('echo 'hello1'' 'echo 'hello2'')

# Loop through commands, open terminal, execute command
for i in "${cmds[@]}"
do
    x-terminal-emulator -e "$i" 