all: q1
q1:
	 gcc -E q1.c > q1.i && gcc -S q1.c && gcc -c q1.c -o q1.o && gcc q1.c -o q1
clean:
	rm -f q1.o q1.i q1.s q1
