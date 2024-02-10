SRCM	= push_swap.c help1.c error.c utiles.c utiles2.c list.c swap.c push.c rotate.c \
	reverse_rotate.c sort.c sort_array.c

# SRCB = bonus/bonus.c bonus/bonus_helper.c parsing.c list_utils.c  list_utils2.c  \
# 	   stack_utils/stack_utils.c stack_utils/stack_utils2.c stack_utils/stack_utils3.c stack_utils/stack_utils4.c

OBJM	= ${SRCM:.c=.o}
# OBJB	= ${SRCB:.c=.o}

NAME = push_swap
#NAME_BONUS = checker

CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address 
CC		= cc
# LIBFTA 	= ./includes/libft/libft.a

all : ${NAME}

#bonus : ${NAME_BONUS}

# ${LIBFTA} : 
# 	@make -C includes/libft

${NAME} : ${OBJM} 
	${CC} ${CFLAGS} ${OBJM}  -o ${NAME}

# ${NAME_BONUS} : ${OBJB} 
# 	${CC} ${CFLAGS} ${OBJB}  -o ${NAME_BONUS} 

clean :
	# @make -C includes/libft clean
	rm -f ${OBJM} ${OBJB}

fclean : clean
	# @make -C includes/libft fclean
	rm -f ${NAME} $(NAME_BONUS)

re : fclean all
