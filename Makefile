all: main.c graph.c list.c
	gcc -o tp0 main.c graph.c list.c -I. -Wall -Wextra -Werror -std=c99 -pedantic -O2 
	