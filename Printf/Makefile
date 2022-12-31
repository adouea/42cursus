# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadoue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 16:21:55 by aadoue            #+#    #+#              #
#    Updated: 2022/12/31 14:58:44 by aadoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c ft_printers.c ft_numlens.c

OBJS = $(FILES:.c=.o)

CC = cc
RM = rm -f
LIB = ar rc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)
	
$(OBJS):
	$(CC) $(CFLAGS) -c $(FILES) 	

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
