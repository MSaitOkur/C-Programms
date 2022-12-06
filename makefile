# linker: compile_main compile_utility
# 	gcc -g -Wall -o test ./lib/main.o ./lib/utility.o -lm

# compile_main: clean ./src/main.c ./inc/utility.h
# 	gcc -g -Wall -I "./inc" -c ./src/main.c -o ./lib/main.o -lm

# compile_utility: clean ./src/utility.c ./inc/utility.h
# 	gcc -g -Wall -I "./inc" -c ./src/utility.c -o ./lib/utility.o -lm

# clean: 
# 	rm -r ./lib/*.o; clear

# --------------------------------------------------
# --------------------------------------------------

run: linker
	./bin/exec_file

linker: compile_main compile_utility compile_mystring
	gcc -g -Wall -o ./bin/exec_file ./lib/main.o ./lib/utility.o ./lib/mystring.o -lm

compile_main: clean ./src/main.c ./inc/utility.h ./inc/mystring.h 
	gcc -g -Wall -I "./inc" -c ./src/main.c -o ./lib/main.o -lm

compile_utility: clean ./src/utility.c ./inc/utility.h ./inc/mystring.h
	gcc -g -Wall -I "./inc" -c ./src/utility.c -o ./lib/utility.o -lm

compile_mystring: clean ./src/mystring.c ./inc/mystring.h ./inc/utility.h
	gcc -g -Wall -I "./inc" -c ./src/mystring.c -o ./lib/mystring.o -lm

clean: 
	# rm ./lib/*.o ./bin/exec_file
	clear