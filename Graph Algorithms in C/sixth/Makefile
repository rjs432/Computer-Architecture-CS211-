all: sixth

sixth: sixth.c
	gcc -Wall -Werror -fsanitize=address sixth.c -o sixth -std=c11

clean:
	rm -f sixth
