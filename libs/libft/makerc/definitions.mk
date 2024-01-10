NAME			:=libft.a

#	Compiler
AR				:=ar
ARFLAGS			:=rcs

#	Remove command
RM				:=rm -rf

#	Compiler flags
CFLAGS			=-Wall -Wextra -Werror -Wpedantic -Wfatal-errors

#	Flags
ifdef	DEBUG
	CFLAGS		+=-g

endif

ifdef	FSAN
	CFLAGS		+=-fsanitize=address,undefined
endif

#	Directories
SRC_DIR		 	:=src
INCLUDE_DIR		:=include
BUILD_DIR		:=build
LIBFT_DIR		:=libft
FT_PRINTF_DIR	:=ft_printf
GET_NEXT_LINE_DIR	:=get_next_line

#	Preprocessing files
SRCS			:=$(wildcard $(SRC_DIR)/$(LIBFT_DIR)/*.c) \
					$(wildcard $(SRC_DIR)/$(FT_PRINTF_DIR)/*.c) \
					$(wildcard $(SRC_DIR)/$(GET_NEXT_LINE_DIR)/*.c)

HEADERS			:=$(INCLUDE_DIR)/*.h

# 	Objects
OBJS 			:=$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
INCLUDE_FLAGS	:=$(addprefix -I, $(sort $(dir $(HEADERS))))
DEPENDS 		:=$(patsubst %.o,%.d,$(OBJS))

# **************************************************************************** #
