##
## EPITECH PROJECT, 2017
## 
## File description:
## 
##

NAME	=	 my_hunter

SRC	=	src/my_hunter.c \
		src/my_printf.c \
		src/my_putchar.c \
		src/my_put_nbr.c \
		src/my_putnbr_base.c \
		src/my_putstr.c \
		src/my_unsigned_put_nbr.c \

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra $(SRC) -o $(NAME) -l c_graph_prog src/struct.h
clean :
	$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)
re : fclean all

.PHONY: all clean fclean re

