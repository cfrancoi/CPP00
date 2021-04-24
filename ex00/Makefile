NAME	= megaphone
SRCS	= megaphone.cpp
CC		= clang++
CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re