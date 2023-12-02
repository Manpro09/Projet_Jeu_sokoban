GCC_FLAGS = Wall -Werror -Wextra -c -ggdb

all: main

main: main.o sokoban.o
	gcc -Wall -o main main.o sokoban.o

.o:
	gcc $(GCC_FLAGS) $*.c

clean:
	rm -f *.o main
