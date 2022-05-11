CC=gcc
CFLAGS=-Wall -Wextra -Werror 

NAME=so_long

SRCS=so_long.c check_map.c get_next_line.c \
	 move_1.c move_2.c draw_map.c ft_move_and_free.c \
	 ft_printf.c ft_printf_function.c \

BSRCS=bonus/so_long_bonus.c bonus/check_map_bonus.c bonus/get_next_line_bonus.c \
	bonus/move_1_bonus.c bonus/move_2_bonus.c bonus/draw_map_bonus.c bonus/ft_move_and_free_bonus.c \
	bonus/ft_printf_bonus.c bonus/ft_printf_function_bonus.c bonus/ft_itoa.c \
		
BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(OBJCTS) -o $(NAME)

all: $(NAME)

bonus : $(BOBJCTS)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(BOBJCTS) -o so_long_bonus

clean:
		rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
		rm -f $(NAME) so_long_bonus
		
re: fclean all	