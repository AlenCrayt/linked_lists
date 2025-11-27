all: main.c
	@vim main.c

run: main.c
	@gcc main.c -o lists
	@./lists
