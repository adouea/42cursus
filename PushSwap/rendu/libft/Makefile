# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadoue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 16:11:19 by aadoue            #+#    #+#              #
#    Updated: 2023/04/12 16:11:23 by aadoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

#Names

NAME := libft.a
SRC_DIR := sources
OBJ_DIR := objects
HDRS_DIR := include
HEADERS := $(addprefix $(HDRS_DIR)/, ft_printf.h get_next_line.h libft.h)
SOURCES := $(addprefix $(SRC_DIR)/, chars/ft_isalnum.c chars/ft_isalpha.c chars/ft_isascii.c chars/ft_isdigit.c chars/ft_ishexadigit.c chars/ft_isprint.c chars/ft_isspace.c chars/ft_putchar_fd.c chars/ft_tolower.c chars/ft_toupper.c checkers/ft_is_int.c checkers/ft_is_long.c checkers/ft_is_number.c ft_printf/ft_numlen.c ft_printf/ft_print_char.c ft_printf/ft_printf.c ft_printf/ft_print_hexa_u.c ft_printf/ft_print_int.c ft_printf/ft_print_str.c ft_printf/ft_print_uint_hexa.c ft_printf/ft_strchr.c ft_printf/ft_strlen.c ft_printf/ft_unumlen.c ft_printf/str_len.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c lst/ft_lstadd_back.c lst/ft_lstadd_front.c lst/ft_lstclear.c lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstlast.c lst/ft_lstm.c lst/ft_lstnew.c lst/ft_lstsize.c memory/ft_bzero.c memory/ft_calloc.c memory/ft_free_double.c memory/ft_free_single.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memset.c memory/ft_raise_error_2.c memory/ft_raise_error.c numbers/ft_atod.c numbers/ft_atof.c numbers/ft_atoi_base.c numbers/ft_atoi.c numbers/ft_atol.c numbers/ft_bin_to_char.c numbers/ft_bitprint.c numbers/ft_bitrev.c numbers/ft_bitswap.c numbers/ft_char_to_bin.c numbers/ft_fmod.c numbers/ft_itoa.c numbers/ft_litoa.c numbers/ft_mod.c numbers/ft_nbrlen.c numbers/ft_part_dec.c numbers/ft_part_int.c numbers/ft_pow.c numbers/ft_print_hex.c numbers/ft_putnbr_fd.c numbers/ft_round_to_int.c numbers/ft_xatof.c numbers/ft_xatoi.c numbers/ft_xitoa.c strings/ft_append_char.c strings/ft_count_occ.c strings/ft_find_index.c strings/ft_n_substr.c strings/ft_putendl_fd.c strings/ft_putstr_fd.c strings/ft_split.c strings/ft_strchr.c strings/ft_strcmp.c strings/ft_strdup.c strings/ft_striteri.c strings/ft_strjoin.c strings/ft_strlcat.c strings/ft_strlcpy.c strings/ft_strlen.c strings/ft_strmapi.c strings/ft_strncmp.c strings/ft_strnstr.c strings/ft_strrchr.c strings/ft_strtrim.c strings/ft_substr.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

#Compilation

CC  := clang
IFLAGS := -I $(HDRS_DIR)
CFLAGS  := -Wall -Wextra -Werror -g
LFLAGS  := -rcs

#Colors

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

#Rules

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS) $(HEADERS)
	@ar $(LFLAGS) $(NAME) $(OBJECTS)
	@printf "(libft) $(YELLOW)Created archive $(NAME)$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $^ -o $@
	@printf "(libft) $(BLUE)Created object $$(basename $@)$(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "(libft) $(RED)Cleaned libft objects\n"

fclean:
	@-rm -rf $(OBJ_DIR) $(NAME)
	@printf "(libft) $(RED)Removing $(NAME)$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
