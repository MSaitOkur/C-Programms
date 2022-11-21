run: linker
	./bin/exec_file

linker: compile_main compile_utility
	gcc -g -Wall -o ./bin/exec_file ./lib/main.o ./lib/utility.o -lm

compile_main: ./src/main.c ./inc/utility.h
	gcc -g -Wall -I "./inc" -c ./src/main.c -o ./lib/main.o -lm

compile_utility: ./src/utility.c ./inc/utility.h
	gcc -g -Wall -I "./inc" -c ./src/utility.c -o ./lib/utility.o -lm

clean: 
	rm *.o ./bin/exec_file
	clear
