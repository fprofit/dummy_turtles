all: turtles
turtles:
	gcc -Wall -Wextra -Werror turt.c -o dummy_turtles
clean:
	rm -f turtles
re: clean all