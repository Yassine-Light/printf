NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror 
ARFLAGS = rcs
SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putnbru.c  ft_puthex.c 
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)


fclean: clean
	$(RM) $(NAME)


re: fclean all 

.PHONY: all clean fclean re
