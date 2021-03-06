all: fifth

fifth: fifth.c
	gcc -Wall -Werror -fsanitize=address fifth.c -o fifth -std=c11

clean:
	rm -f fifth
