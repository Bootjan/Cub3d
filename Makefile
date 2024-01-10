include makerc/definitions.mk

all: build_dir $(NAME)
.PHONY: all

build_dir:
	$(shell mkdir -p $(dir $(OBJS)))
.PHONY: build_dir

$(NAME): $(MLX42) $(LIBFT) $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(MLX42) $(LIBFT) -o $(NAME)

-include $(DEPENDS)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(MLX42):
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:	
	@$(RM) $(OBJS) $(DEPENDS)
.PHONY: clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BUILD_DIR)
.PHONY: fclean

re: fclean all
.PHONY: re

clean_submodules: clean
	@$(RM) $(MLX42_DIR)/build
	@$(MAKE) -C $(LIBFT_DIR) fclean
.PHONY: clean_submodules

debug:
	@$(MAKE) DEBUG=1 LOG=1
.PHONY: debug

apple:
	@$(MAKE) APPLE=1
.PHONY: apple

applebug:
	@$(MAKE) APPLE=1 DEBUG=1
.PHONY: applebug

fsan:
	@$(MAKE) FSAN=1 DEBUG=1 LOG=1
.PHONY: fsan

resan: fclean fsan
.PHONY: resan

rebug: fclean debug
.PHONY: rebug

reapple: fclean apple
.PHONY: reapple

reapplebug: fclean applebug
.PHONY: reapplebug
