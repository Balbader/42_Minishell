# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 10:43:48 by baalbade          #+#    #+#              #
#    Updated: 2023/10/09 13:20:50 by ftuernal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME				:=	minishell


##############
# SRCS FILES #
##############

# BUILTINS FILES

CD_DIR				:=	cd/
CD_FILES			:=	\
						ft_change_working_directory.c \
						ft_create_working_directory.c \
						ft_exec_cd.c \
						ft_get_cd_path.c \
						ft_get_token_len.c \
						ft_replace_working_directory.c
CD					:=	$(addprefix $(CD_DIR), $(CD_FILES))

ECHO_DIR			:=	echo/
ECHO_FILES			:=	\
						ft_check_n_flag.c \
						ft_exec_echo.c
ECHO				:=	$(addprefix $(ECHO_DIR), $(ECHO_FILES))

ENV_DIR				:=	env/
ENV_FILES			:=	\
						ft_add_var_to_env.c \
						ft_compare_keys.c \
						ft_convert_env_to_tab.c \
						ft_create_env_list.c \
						ft_del_env.c \
						ft_del_node.c \
						ft_exec_env.c \
						ft_find_value.c \
						ft_get_env.c \
						ft_get_env_len.c \
						ft_get_env_utils.c \
						ft_get_key_section.c \
						ft_get_last_env.c \
						ft_get_value_len.c \
						ft_get_value_section.c \
						ft_modif_shlvl.c
ENV					:=	$(addprefix $(ENV_DIR), $(ENV_FILES))

EXIT_DIR			:=	exit/
EXIT_FILES			:=	\
						ft_exec_exit.c \
						ft_remove_quotes.c \
						ft_str_is_digit.c
EXIT				:=	$(addprefix $(EXIT_DIR), $(EXIT_FILES))

EXPORT_DIR			:=	export/
EXPORT_FILES		:=	\
						ft_check_cpy.c \
						ft_copy_key_and_equal.c \
						ft_does_value_exist.c \
						ft_exec_export.c \
						ft_get_key.c \
						ft_get_key_len.c
EXPORT				:=	$(addprefix $(EXPORT_DIR), $(EXPORT_FILES))

PWD_DIR				:=	pwd/
PWD_FILES			:=	ft_exec_pwd.c
PWD					:=	$(addprefix $(PWD_DIR), $(PWD_FILES))

UNSET_DIR			:=	unset/
UNSET_FILES			:=	\
						ft_check_var_to_unset.c \
						ft_exec_unset.c
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
EXEC_FILES			:= \
					   exec.c \
					   exec_fork.c \
					   exec_heredoc.c \
					   exec_init.c \
					   exec_list_utils.c \
					   exec_rdir.c \
					   exec_utils.c \
					   exec_utils2.c \
					   exec_utils3.c \
					   launch_execution.c
EXEC				:=	$(addprefix $(EXEC_DIR), $(EXEC_FILES))


# EXPAND FILES

EXPAND_DIR			:=	expand/
EXPAND_FILES		:=	\
						check_arglist.c \
						expand.c \
						expand_quote_word.c \
						expand_quote_word_utils.c \
						expand_var.c \
						expand_var_utils.c \
						quote_remove.c
EXPAND				:=	$(addprefix $(EXPAND_DIR), $(EXPAND_FILES))


# PARSER FILES

PARSER_DIR			:=	parse/
PARSER_FILES		:=	\
						count_token.c \
						parse_input.c \
						parse_verif.c \
						split_into_words.c \
						tokenizer.c \
						word_node_utils.c
PARSER				:=	$(addprefix $(PARSER_DIR), $(PARSER_FILES))

SIG_DIR				:=	signal/
SIG_FILES			:=	\
						ft_handle_signal.c \
						ft_init_signal.c \
						ft_sig_heredoc.c
SIG					:=	$(addprefix $(SIG_DIR), $(SIG_FILES))

UTILS_DIR			:=	utils/
UTILS_FILES			:=	\
						dump_add.c \
						dump_del.c \
						free_2_str.c \
						ft_add_slash.c \
						ft_check_cmd_for_builtins.c \
						ft_del_tokens.c \
						ft_delete_all.c \
						ft_free_all_env.c \
						ft_free_cmd.c \
						ft_free_tabs.c \
						ft_get_tab_len.c \
						ft_join_all_str.c \
						ft_print_cmd_error.c \
						ft_print_error_msg.c \
						ft_print_exit_error.c \
						ft_print_export_error.c \
						ft_print_redir_error.c \
						ft_print_sig_error.c \
						ft_print_unset_error.c \
						ft_run_builtins.c \
						ft_strchr_bool.c \
						get_tab_len.c \
						join_free.c \
						loop_joinf.c \
						quote_utils.c
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))


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
						$(SIG) \
						$(UTILS) \
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
