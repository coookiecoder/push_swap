files = atoi check error list list_utils main setup swap push rotate find_cost reset solve_3 solve

sources = $(foreach buffer, $(files), sources/$(buffer).c)

ft_printf = ft_printf/libftprintf.a

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(ft_printf)
	$(CC) $(sources) $(ft_printf) $(CFLAGS) -o $(NAME)

$(ft_printf):
	make -C ft_printf

$(ft_printf)clean:
	make -C ft_printf clean

$(ft_printf)fclean:
	make -C ft_printf fclean

$(ft_printf)re:
	make -C ft_printf re

clean: $(ft_printf)clean

fclean: $(ft_printf)fclean clean
	rm -rf $(NAME)

re: $(ft_printf)re fclean all

debug: all
	$(CC) $(sources) $(ft_printf) $(CFLAGS) -o $(NAME) -g3 -fsanitize=address

.PHONY: all clean fclean re debug
