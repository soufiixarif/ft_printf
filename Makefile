NAME = libftprintf.a
SRC_NAME = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_putptr.c
CC = cc
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC_NAME:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
%o : %c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
