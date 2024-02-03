NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
CFILES = push_swap.c help1.c error.c utiles.c utiles2.c list.c

OFILSE = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILSE)

.c.o:
	$(CC) $(CFLAGS) -c $<
	ar rc $(NAME) $@

clean:
	rm -f $(OFILSE) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
