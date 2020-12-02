compile1:
# 	Compile your code for first part here
	gcc k.c -o k -lpthread

run1: compile1
# 	 Execute part 1 here
	./k

compile2:
# 	Compile your code for second part here
	gcc -o k2 k2.c -lpthread

run2: compile2
#	Execute part 2 here
	./k2

clean:
	rm -f *.out k k2
