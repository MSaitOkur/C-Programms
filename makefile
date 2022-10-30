run: linker
	clear
	./bin/exec_file

linker: compile_main
	gcc -o ./bin/exec_file ./lib/main.o

compile_main: ./src/main.c
	gcc -Wall -I "./include" -lm -c ./src/main.c -o ./lib/main.o

clean:
	rm *.o ./bin/exec_file
