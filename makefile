all:
	gcc -g3 -Wall -Wextra -Werror *.c -o ls_demo

clean:
	find . -perm +100 -type f -delete