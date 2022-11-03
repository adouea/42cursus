FILES = ft_.c tout tapper

OBJS = $(FILES:.c=.o)

NAME = libft.a

CC = cc
RM = rm -f
LIB = ar rc
CFLAGS = -Werror -Wall -Wextra

all : $(NAME)
	
$(NAME): $(OBJS)
	$(LIB) $(NAME)

$(OBJS):
	$(CC) $(CLAGS) -c $(FILES) 	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
