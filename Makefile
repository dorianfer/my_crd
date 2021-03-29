##
## ETNA PROJECT, 03/10/2020 by fernan_d
## Makefile
## File description:
##      [...]
##

NAME = 	test
SRC =	my_crd.c
CFLAGS = -Wall -Wextra -Werror -std=c11

$(NAME):
			gcc $(CFLAGS) $(SRC) -o my_crd 

all:		$(NAME)

.PHONY:		 all 
