run: linker
	./bin/exec_file

linker: compile_main compile_utility_header
	gcc -g -Wall -o ./bin/exec_file ./lib/main.o ./lib/utility_header.o -lm

compile_main: ./src/main.c ./inc/utility_header.h
	gcc -g -Wall -I "./inc" -c ./src/main.c -o ./lib/main.o -lm

compile_utility_header: ./src/utility_header.c ./inc/utility_header.h
	gcc -g -Wall -I "./inc" -c ./src/utility_header.c -o ./lib/utility_header.o -lm

clean: 
	rm *.o ./bin/exec_file
	clear
