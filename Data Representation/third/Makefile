all: third

third: third.c
	gcc -Wall -Werror -fsanitize=address third.c -o third -std=c11

clean:
	rm -f third
