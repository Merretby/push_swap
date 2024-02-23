NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address 
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


#SRCM	= push_swap.c help1.c error.c utiles.c utiles2.c list.c swap.c push.c rotate.c \
	reverse_rotate.c sort.c sort_array.c sort_array2.c

# SRCB = bonus/bonus.c bonus/bonus_helper.c parsing.c list_utils.c  list_utils2.c  \
# 	   stack_utils/stack_utils.c stack_utils/stack_utils2.c stack_utils/stack_utils3.c stack_utils/stack_utils4.c

#OBJM	= ${SRCM:.c=.o}
# OBJB	= ${SRCB:.c=.o}

#NAME = push_swap
#NAME_BONUS = checker

#CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address 
#CC		= cc
# LIBFTA 	= ./includes/libft/libft.a

#all : ${NAME}

#bonus : ${NAME_BONUS}

# ${LIBFTA} : 
# 	@make -C includes/libft

#${NAME} : ${OBJM} 
#	${CC} ${CFLAGS} ${OBJM}  -o ${NAME}

# ${NAME_BONUS} : ${OBJB} 
# 	${CC} ${CFLAGS} ${OBJB}  -o ${NAME_BONUS} 

#clean :
#	# @make -C includes/libft clean
#	rm -f ${OBJM} ${OBJB}

#fclean : clean
#	# @make -C includes/libft fclean
#	rm -f ${NAME} $(NAME_BONUS)

#re : fclean all
