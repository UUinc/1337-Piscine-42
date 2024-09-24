SRCS = srcs/ft_atoi.c srcs/ft_do_op.c srcs/ft_putnbr.c srcs/ft_utils.c srcs/main.c
OBJS = ${SRCS:.c=.o}
NAME = do-op
FLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc

all:
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
