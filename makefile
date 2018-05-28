### Makefile ###
#Para compilar digite no terminal "make project"
project:
	gcc -c ST.h
	gcc -c Item.h
	gcc -c ST.c
	gcc -c Item.c
	gcc -c main.c
	gcc -o main main.o ST.o Item.o
	./main -n5 < tale.txt
	rm -rf main.o
	rm -rf ST.o
	rm -rf Item.o
	rm -rf ST.h.gch
	rm -rf Item.h.gch
	rm -rf main
	#clear
