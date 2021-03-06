all: fourth

fourth: fourth.c
	gcc -Wall -Werror -fsanitize=address fourth.c -o fourth -std=c11

clean:
	rm -f fourth
