# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadoue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 13:36:18 by aadoue            #+#    #+#              #
#    Updated: 2023/02/20 13:39:11 by aadoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog

FILES = test_mini_libx.c
 
OBJS = $(FILES:.c=.o)

CC = clang
RM = rm -f
LIB = ar rc
CFLAGS = -Werror -Wall -Wextra

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
