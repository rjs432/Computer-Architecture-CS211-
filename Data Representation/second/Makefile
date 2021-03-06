all: second

second: second.c
	gcc -Wall -Werror -fsanitize=address second.c -o second -std=c11

clean:
	rm -f second
