all: fifth

fifth: fifth.c
	gcc -g -Wall -Werror -fsanitize=address fifth.c -o fifth -std=c11 -lm

clean:
	rm -f fifth
