FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJS = ${FILES:.c=.o}

HEADERS = ft.h

SUBDIR = ./srcs/ft_putchar.c /
	./srcs/ft_swap.c /
	./srcs/ft_putstr.c /
	./srcs/ft_strlen.c /
	./srcs/ft_strcmp.c

HEADFOLD = ./includes/ft.h

NAME = rush-02

CC = gcc
RM = rm -f
LIB = ar rc

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
        ${LIB} libft.a ${SUBDIR}/$@ ${OBJS} ${HEADFOLD}/$@ ${HEADERS}
        ${CC} -g -o ${NAME} ${CFLAGS} main.c -L. -lft

all :
	${NAME}

clean :
	${RM}${OBJS}

fclean: clean
        ${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

