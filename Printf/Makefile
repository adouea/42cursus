# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadoue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 16:21:55 by aadoue            #+#    #+#              #
#    Updated: 2023/01/03 16:50:36 by aadoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c ft_strlen.c ft_print_char.c ft_print_str.c ft_print_int.c ft_print_uint_hexa.c ft_numlen.c ft_unumlen.c ft_print_hexa_u.c ft_strchr.c
 
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
