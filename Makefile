NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude

SRC_DIR		= src
OBJ_DIR		= obj

SRC_FILES	= \
	main.c \
	parse_args.c \
	stack.c \
	ops_swap.c \
	ops_push.c \
	ops_rotate.c \
	ops_rev_rotate.c \
	disorder.c \
	strategy_simple.c \
	strategy_medium.c \
	strategy_complex.c \
	strategy_adaptive.c \
	bench.c \
	utils.c

SRCS		= $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
