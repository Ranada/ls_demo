CC = gcc -g3 -Wall -Wextra -Werror

all:
	${CC} *.c -o ls_demo

clean:
	find . -perm +100 -type f -delete