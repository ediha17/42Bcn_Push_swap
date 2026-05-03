# +==========================+
# |           NAME           |
# +==========================+

NAME = push_swap

# +==========================+
# |         COMPILER         |
# +==========================+

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

# +==========================+
# |       DIRECTORIES        |
# +==========================+

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incs

# +==========================+
# |         SOURCES          |
# +==========================+

SRCS = $(wildcard $(SRC_DIR)/*.c)

# +==========================+
# |         INCLUDES         |
# +==========================+

INC = $(wildcard $(INC_DIR)/*)

# +==========================+
# |         OBJECTS          |
# +==========================+

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# +==========================+
# |          RULES           |
# +==========================+

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
