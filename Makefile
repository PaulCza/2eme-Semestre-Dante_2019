##
## Makefile
## File description:
## oh bordel
##



all: 
	make -C generator/
	make -C solver/

.PHONY: all clean fclean re tests_run

