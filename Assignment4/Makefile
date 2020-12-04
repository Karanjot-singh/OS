compile1:
# 	Compile your code for first part here
	gcc k.c -o k -lpthread -w

run1: compile1
# 	 Execute part 1 here
	./k1

compile1:
# 	Compile your code for second part here
	gcc -o k1 nonblocking_2019050.c -lpthread -w

run2: compile2
# 	 Execute part 1 here
	./k2

compile2:
# 	Compile your code for second part here
	gcc -o k2 blocking_2019050.c -lpthread -w

clean:
	rm -f *.out k k2
