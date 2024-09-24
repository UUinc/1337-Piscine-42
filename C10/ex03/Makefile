CC = cc
CFLAGS = -Wall -Wextra -Werror
ADDRFLAGS = -fsanitize=address
INC = -I includes
FILES = srcs/*.c
OBJS = ${FILES:.c=.o}
RM = rm -f
NAME = ft_hexdump
TEST = test

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${FILES} ${INC} -o ${NAME}

test:
	${CC} ${CFLAGS} ${FILES} ${INC} ${ADDRFLAGS} -o ${TEST}

clean:
	${RM} ${OBJS} ${TEST}

fclean: clean
	${RM} ${NAME}

re: fclean all
