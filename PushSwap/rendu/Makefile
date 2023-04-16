# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadoue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 16:11:49 by aadoue            #+#    #+#              #
#    Updated: 2023/04/12 16:11:52 by aadoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

#Names

MAIN := push_swap
BONUS := checker
SRC_DIR := sources
HDRS_DIR := include
OBJ_DIR := objects
LIBFT_DIR := libft
MAIN_OBJ := $(OBJ_DIR)/$(MAIN).o
BONUS_OBJ := $(OBJ_DIR)/$(BONUS).o
LIBFT := $(LIBFT_DIR)/libft.a
HEADERS := $(addprefix $(HDRS_DIR)/, push_swap.h)
SOURCES = $(addprefix $(SRC_DIR)/, basic_moves.c bonus.c checker.c checks.c count_moves.c finder.c push_swap.c sort.c stack.c turk.c)
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.c=.o))	

#Compilation

CC  := clang
IFLAGS := -Iinclude -I$(LIBFT_DIR)/include
CFLAGS := -Wall -Wextra -Werror -g3 
LFLAGS := -Llibft -lft

#Colors

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

#Rules

all: $(LIBFT) $(MAIN)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(MAIN): $(LIBFT) $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(subst $(BONUS_OBJ),,$(OBJECTS)) $(LFLAGS) -o $(MAIN)
	@printf "(push_swap) $(GREEN)Created executable $(MAIN)$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@printf "(push_swap) $(BLUE)Created object $$(basename $@)$(RESET)\n"

bonus: $(LIBFT) $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(subst $(MAIN_OBJ),,$(OBJECTS)) $(LFLAGS) -o $(BONUS)
	@printf "(push_swap) $(GREEN)Created executable $(BONUS)$(RESET)\n"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) --quiet
	@rm -rf $(OBJ_DIR)
	@printf "(push_swap) $(RED)Cleaned push_swap objects\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --quiet
	@-rm -rf $(MAIN) $(BONUS) $(OBJ_DIR)
	@printf "(push_swap) $(RED)FCleaned push_swap objects\n"
	@printf "(push_swap) $(RED)Removing executables\n"

re: fclean all

.PHONY: all, clean, fclean, re
