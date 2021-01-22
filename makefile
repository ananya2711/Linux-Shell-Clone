all:
	gcc ls.c -o ls
	gcc cat.c -o cat
	gcc date.c -o date
	gcc rm.c -o rm
	gcc mkdir.c -o mkdir
	gcc -c file.c
	gcc file.o
	./a.out
obj_files:
	gcc ls.c -o ls
	gcc cat.c -o cat
	gcc date.c -o date
	gcc rm.c -o rm
	gcc mkdir.c -o mkdir
assembling:
	gcc -c file.c
linking:
	gcc file.o
run:
	./a.out