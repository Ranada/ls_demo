all:
	gcc -Wall -Wextra -Werror *.c -o ls_demo

clean:
	find . -perm +100 -type f -delete