NAME = so_long
CC = cc
CFLAGS = -g -fsanitize=address
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
SRC_DIR = ./src
INC_DIR = ./include
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX_FLAGS = -L$(INC_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/get_next_line.c \
	$(SRC_DIR)/get_next_line_utils.c \
	$(SRC_DIR)/open_map.c \
	$(SRC_DIR)/init_grid.c \
	$(SRC_DIR)/texture_handler.c \
	$(SRC_DIR)/draw_map.c \
	$(SRC_DIR)/map_utils.c \
	$(SRC_DIR)/check_utils.c \
	$(SRC_DIR)/movement.c \
	$(SRC_DIR)/map_checks.c \
	$(SRC_DIR)/count_checks.c \
	
OBJS = $(SRCS:.c=.o)

LIBS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

all: $(LIBFT) $(PRINTF) $(NAME)

# Compile libft
$(LIBFT):
	@echo "Compiling libft"
	@$(MAKE) -C $(LIBFT_DIR)

# Compile printf with root libft
$(PRINTF): $(LIBFT)
	@echo "Compiling ft_printf"
	@$(MAKE) -C $(PRINTF_DIR)

# Compile so_long
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "Compiling $(NAME)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME) created successfully"

# compile object files to output
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)/include -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "Clean completed."

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "Full clean completed."

re: fclean all

.PHONY: all clean fclean re
