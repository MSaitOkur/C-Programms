run: linker
	clear
	./bin/exec_file

linker: compile_main compile_utility_header
	gcc -o ./bin/exec_file ./lib/main.o ./lib/utility_header.o

compile_main: ./src/main.c ./inc/utility_header.h
	gcc -Wall -I "./inc" -lm -c ./src/main.c -o ./lib/main.o

compile_utility_header: ./src/utility_header.c ./inc/utility_header.h
	gcc -Wall -I "./inc" -lm -c ./src/utility_header.c -o ./lib/utility_header.o

clean:
	rm *.o ./bin/exec_file
