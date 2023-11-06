files = putchar_fd putstr_fd putnbr_fd putunbr_fd puthexl_fd puthexu_fd putptr_fd strlen printf

sources = $(foreach buffer, $(files), ft_$(buffer).c)

objects = $(foreach buffer, $(files), ft_$(buffer).o)

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(objects)
	ar -rc $(NAME) $(objects)

clean:
	rm -rf $(objects)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: all
	$(CC) $(CFLAGS) main.c $(NAME) -o OUTPUT

.PHONY: all clean fclean re debug
