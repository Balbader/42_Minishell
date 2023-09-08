# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 10:43:48 by baalbade          #+#    #+#              #
#    Updated: 2023/09/08 10:43:49 by baalbade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME				:=	minishell


##############
# SRCS FILES #
##############

# BUILTINS FILES

CD_DIR				:=	cd/
CD_FILES			:=	cd.c
CD					:=	$(addprefix $(CD_DIR), $(CD_FILES))

ECHO_DIR			:=	echo/
ECHO_FILES			:=	echo.c
ECHO				:=	$(addprefix $(ECHO_DIR), $(ECHO_FILES))

ENV_DIR				:=	env/
ENV_FILES			:=	env.c
ENV					:=	$(addprefix $(ENV_DIR), $(ENV_FILES))

EXIT_DIR			:=	exit/
EXIT_FILES			:=	exit.c
EXIT				:=	$(addprefix $(EXIT_DIR), $(EXIT_FILES))

EXPORT_DIR			:=	export/
EXPORT_FILES		:=	export.c
EXPORT				:=	$(addprefix $(EXPORT_DIR), $(EXPORT_FILES))

PWD_DIR				:=	pwd/
PWD_FILES			:=	pwd.c
PWD					:=	$(addprefix $(PWD_DIR), $(PWD_FILES))

UNSET_DIR			:=	unset/
UNSET_FILES			:=	unset.c
UNSET				:=	$(addprefix $(UNSET_DIR), $(UNSET_FILES))


BUILT_DIR			:=	builtins/
BUILT_SRCS			:=	\
						$(CD) \
						$(ECHO) \
						$(ENV) \
						$(EXIT) \
						$(EXPORT) \
						$(PWD) \
						$(UNSET)
BUILT				:=	$(addprefix $(BUILT_DIR), $(BUILT_SRCS))


# EXEC FILES

EXEC_DIR			:=	exec/
EXEC_FILES			:=	exec_cmd.c
EXEC				:=	$(addprefix $(EXEC_DIR), $(EXEC_FILES))


# EXPAND FILES

EXPAND_DIR			:=	expand/
EXPAND_FILES		:=	exec_cmd.c
EXPAND				:=	$(addprefix $(EXEC_DIR), $(EXEC_FILES))


# PARSER FILES

PARSER_DIR			:=	parse/
PARSER_FILES		:=	\
						addback_cmdline_node.c \
						addback_word_node.c \
						alloc_parse_struct.c \
						append_cmd_node.c \
						append_word_node.c \
						check_quotes.c \
						cmdline_new_node.c \
						cust_getenv.c \
						goto_last_node.c \
						goto_last_word.c \
						parse_input.c \
						quote_on.c \
						sep_cmd_line.c \
						sep_in_words.c \
						word_new_node.c
PARSER				:=	$(addprefix $(EXEC_DIR), $(EXEC_FILES))


###############
# INGREDIENTS #
###############

# LIBFT
LIBFT_PATH			:=	./libft/
LIBFT				:=	$(LIBFT_PATH)/libft.a
MAKE_LIBFT			:=	make -C $(LIBFT_PATH)
LIB_FLAGS			:=	-L $(LIBFT_PATH) -lft -lreadline

# INC
INC_DIR				:=	./inc/

# SRCS
SRCS_DIR			:=	./srcs/
SRCS				:=	\
						$(BUILT) \
						$(EXEC) \
						$(EXPAND) \
						$(PARSER) \
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

# BUILD
BUILD_DIR			:=	.build
OBJS				:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS				:=	$(OBJS:.o=.d)

# FLAGS
CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -g3
IFLAGS   	 		:=	-I $(INC_DIR)

# BASH FUNCTIONS
RM					:=	rm -r -f
MAKEFLAGS   		+= --silent --no-print-directory
DIR_DUP				=	mkdir -p $(@D)


##########
# COLORS #
##########
RED					:=	\033[0;31m
GREEN				:=	\033[0;32m
YELLOW				:=	\033[0;33m
RESET				:=	\033[0m

###########
# RECIPES #
###########

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_FLAGS)
	@echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) ready!"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE_LIBFT)

-include $(DEPS)

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@$(RM) $(BUILD_DIR) $(OBJS) $(DEPS)
	@$(MAKE_LIBFT) clean
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE_LIBFT) fclean
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

re: fclean 
	make all
	$(MAKE_LIBFT) re

.PHONY: all clean fclean re
