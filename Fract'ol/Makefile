# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadoue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:54:31 by aadoue            #+#    #+#              #
#    Updated: 2023/02/17 16:25:14 by aadoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiled

NAME = fractol
MLX = libmlx.a
LIBFT = libft.a

#Directories

SRCS_DIR = srcs
HDRS_DIR = include
MLX_DIR = mlx
LIBFT_DIR = libft

#Headers

HDRS = $(addprefix $(HDRS_DIR)/, complex.h fractol.h utils.h)
MLX_HDRS = $(addprefix $(MLX_DIR)/, mlx.h)
LIBFT_HDRS = $(addprefix $(LIBFT_DIR)/, libft.h)

#Files

SRCS = $(addprefix $(SRCS_DIR)/, draw.c complex.c events.c fractol.c utils.c)
OBJS = $(SRCS:.c=.o)

#Actions

CC = clang
CFLAGS = -Werror -Wall -Wextra
GCC = $(CC) $(FLAGS)

#Rules

all: $(NAME)

%.o: %.c $(HDRS) $(MLX_HDRS) $(LIBFT_HDRS)
	$(GCC) -c -o $@ $<

$(NAME): $(OBJS)
	cd $(LIBFT_DIR) && $(MAKE)
	cd $(MLX_DIR) && $(MAKE)
	$(GCC) $(OBJS) -L$(MLX_DIR) -lmlx -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	cd $(MLX_DIR) && $(MAKE) clean
	cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(MLX_DIR) && $(MAKE) fclean
	cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
