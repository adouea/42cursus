# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadoue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 16:21:55 by aadoue            #+#    #+#              #
#    Updated: 2022/11/09 18:38:45 by aadoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c

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
