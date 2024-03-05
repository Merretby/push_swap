NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address 
CFILES = push_swap.c help1.c error.c utiles.c utiles2.c list.c ruels/swap.c ruels/push.c ruels/rotate.c \
	ruels/reverse_rotate.c sort.c sort_array.c sort_array2.c
CBFILES = checker.c help1.c error.c utiles.c utiles2.c list.c ruels/swap.c ruels/push.c ruels/rotate.c \
	ruels/reverse_rotate.c sort.c sort_array.c sort_array2.c bonus/get_next_line_bonus.c \
	bonus/get_next_line_utils_bonus.c
OFILSE = $(CFILES:.c=.o)
OBFILSE = $(CBFILES:.c=.o)


all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OFILSE)
	$(CC) $(CFLAGS) $(OFILSE) -o $(NAME)

$(NAME_BONUS): $(OBFILSE)
	$(CC) $(CFLAGS) $(OBFILSE) -o $(NAME_BONUS)

clean:
	rm -f $(OFILSE) $(OBFILSE)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
