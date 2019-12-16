main : main.o projet2019.o
	gcc main.o projet2019.o -o main
main.o : main.c projet2019.h
	gcc -c -Wall main.c
projet2019.o : projet2019.c
	gcc -c -Wall projet2019.c
clean :
	rm *.o

