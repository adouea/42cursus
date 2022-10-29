FILES = ft_*.c

OBJS = ${FILES:.c=.o}

HEADERS = libft.h

NAME = libft.a

CC = cc
RM = rm -f
LIB = ar rc

CFLAGS = -Werror -Wall -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIB} libstr.a ${OBJS} ${HEADERS}

all :
	${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
