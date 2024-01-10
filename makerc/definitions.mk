NAME			:=cub3d

#	Compiler
CC				:=cc

#	Remove command
RM				:=rm -rf

#	Compiler flags
CFLAGS			=-Wall -Wextra -Werror -Wpedantic -Wfatal-errors
LDFLAGS			:=-lglfw -lm
DFLAGS			:=-MMD -MP

#	Flags
ifdef	DEBUG
	CFLAGS		+=-g

endif

ifdef	FSAN
	CFLAGS		+=-fsanitize=address,undefined
endif

ifdef LOG
	CFLAGS		+=-DLOG=1
endif

ifdef	APPLE
	LDFLAGS		+=-L"/opt/homebrew/Cellar/glfw/3.3.9/lib"
endif

#	Directories
SRC_DIR		 	:=src
INCLUDE_DIR		:=include
BUILD_DIR		:=build
LIBS_DIR		:=libs
MLX42_DIR		=$(LIBS_DIR)/MLX42
LIBFT_DIR		=$(LIBS_DIR)/libft
LIBFT 			=$(LIBFT_DIR)/libft.a
MLX42			=$(MLX42_DIR)/$(BUILD_DIR)/libmlx42.a

#	Preprocessing files
SRCS			:=$(wildcard $(SRC_DIR)/*.c) \
						$(wildcard $(SRC_DIR)/error/*.c) \
						$(wildcard $(SRC_DIR)/parse/*.c) \
						$(wildcard $(SRC_DIR)/rgb/*.c) \
						$(wildcard $(SRC_DIR)/scene/*.c) \
						$(wildcard $(SRC_DIR)/init/*.c) \
						$(wildcard $(SRC_DIR)/dda/*.c) \
						$(wildcard $(SRC_DIR)/utils/*.c) \
						$(wildcard $(SRC_DIR)/move_player/*.c) \
						$(wildcard $(SRC_DIR)/rectangle/*.c)

HEADERS			:=$(INCLUDE_DIR)/*.h \
					$(LIBFT_DIR)/include/*.h \
					$(MLX42_DIR)/include/*.h

# 	Objects
OBJS 			:=$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
INCLUDE_FLAGS	:=$(addprefix -I, $(sort $(dir $(HEADERS))))
DEPENDS 		:=$(patsubst %.o,%.d,$(OBJS))

# **************************************************************************** #
