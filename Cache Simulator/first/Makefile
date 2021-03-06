all: first

first: first.c
	gcc -Wall -Werror -fsanitize=address first.c -o first -lm -g

clean:
	rm -f first
