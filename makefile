### Makefile ###
#Para compilar digite no terminal "make project"
project:
	gcc -c ST.h
	gcc -c Item.h
	gcc -c ST.c
	gcc -c Item.c
	gcc -c main.c
	gcc -o Projeto2 main.o ST.o Item.o
	./Projeto2 -n10 < tale.txt
	rm -rf main.o
	rm -rf ST.o
	rm -rf Item.o
	rm -rf ST.h.gch
	rm -rf Item.h.gch
	rm -rf Projeto2
	#clear