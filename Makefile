all: main.c
	@vim main.c

run: main.c
	@gcc -Wall -Werror main.c -o lists
	@./lists
