all:
	gcc -c src/lex.c -I includes -o exe/lex.o

	gcc src/main.c exe/*.o -I includes -o exe/main
	rm -r exe/*.o