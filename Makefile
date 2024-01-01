MAIN = main.c
# FILES = handling_args.c utils.c life_of_philo.c thread_utils.c stop_threads.c have_diner.c

SRCS = $(MAIN)\
$(FILES)

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
NAME = cub3d
VPATH = . src

I_DIRS := $(shell find . -type f -name "*.h" -exec dirname {} + | uniq)
INCLUDE = $(I_DIRS:%=-I%)

MLX42 = build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.9/lib/"
MLX42_DIR = MLX42
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address -g
OBJS_DIR = ./objs

RM = rm -rf

all:	$(NAME)

$(NAME): $(MLX42) $(LIBFT) $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) -o $(NAME)
	@echo "$(NAME) made!"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "./objs made!"

$(OBJS_DIR)/%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(MLX42):
	@cmake $(MLX42_DIR) -B build
	@cmake --build build

$(LIBFT):
	@make -C $(LIBFT_DIR) all

clean:	
	@$(RM) -r $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(NAME) objects removed!"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed!"
	@$(RM) $(OBJS_DIR)
	@echo "./objs removed!"
	@make -C $(LIBFT_DIR) fclean
	@$(RM) build

re: fclean all

.PHONY: all clean re clean fclear

