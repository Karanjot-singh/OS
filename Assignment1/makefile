all: main
main: ls
	 gcc q2.c && ./a.out
ls: cat
	 gcc ls.c -o ls
cat: date
	gcc cat.c -o cat
date: rm
	gcc date.c -o date
rm: mkdir
	gcc rm.c -o rm
mkdir:
	gcc mkdir.c -o mkdir
clean :
	rm -f *.o ls cat date rm mkdir
	rm -f *.out a  