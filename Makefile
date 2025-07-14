NAME := game
SRC_FILES := main.c
SRC_FILES := $(addprefix src/, $(SRC_FILES))
OBJ_FILES := $(SRC_FILES:.c=.o)
HEADER_FILES := game.h
HEADER_FILES := $(addprefix include/, $(HEADER_FILES))
CC := cc
CFLAGS := -Wall -Wextra #-Werror
RM = rm -rf
INCLUDING := -I./include
LINKING := -lX11 -lm

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(INCLUDING) $(SRC_FILES) -o $(NAME) $(LINKING)

clean:
	$(RM) $(OBJ_FILES)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
