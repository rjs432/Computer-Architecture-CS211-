all: second

second: second.c
	gcc -Wall -Werror -fsanitize=address second.c -o second -lm -g

clean:
	rm -f second
