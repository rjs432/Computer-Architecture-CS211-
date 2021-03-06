all: first

first: first.c
	gcc -Wall -Werror -fsanitize=address first.c -o first -std=c11

clean:
	rm -f first
