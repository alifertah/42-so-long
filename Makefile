CC=cc
CFLAGS=-Wall -Wextra -Werror 

NAME=so_long

SRCS=so_long.c check_map.c get_next_line.c \
	 move_1.c move_2.c draw_map.c ft_move_and_free.c \
	 ft_printf.c ft_printf_function.c \

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(OBJCTS) -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
		rm -f $(NAME) so_long_bonus
		
re: fclean all	