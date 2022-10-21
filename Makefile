CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_putchar.c ft_printf.c ft_putnbr_base.c ft_putnbr_base2.c ft_printaddress.c ft_putstr.c

OBJ = $(SRC:.c=.o)


.c.o : $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	ar -rc  $(NAME) $(OBJ)

bonus : $(OBJ)
	ar -rc  $(NAME) $(OBJ)

all : $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o ft_printf.so $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re