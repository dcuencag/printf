NAME printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 

OBJ = $(SRC:.C=.0)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm-f $(NAME)
re:	fclean all

.PHONY: all clean fclean re