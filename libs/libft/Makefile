include makerc/definitions.mk

all: build_dir $(NAME)
.PHONY: all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

build_dir:
	$(shell mkdir -p $(dir $(OBJS)))
.PHONY: build_dir

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(DEPENDS)
.PHONY: clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BUILD_DIR)
.PHONY: fclean

re: fclean all
.PHONY: re

debug:
	@$(MAKE) DEBUG=1
.PHONY: debug

fsan:
	@$(MAKE) FSAN=1 DEBUG=1
.PHONY: fsan

resan: fclean fsan
.PHONY: resan

rebug: fclean debug
.PHONY: rebug
