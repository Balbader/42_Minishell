#this makefile is intended to compile sources to test parse and expand sources

TARGET		= ./print

PARSEDIR	= parse/
PARSEFILES	= \
				count_token.c \
				parse_input.c \
				quote_utils.c \
				split_into_words.c \
				tokenizer.c \
				word_node_utils.c \
				print_parser.c
PARSE		= $(addprefix $(PARSEDIR, $(PARSEFILES)))

EXPANDIR	= expand/
EXPANDFILES	= \
				expand.c \
				expand_words.c \
				expand_var.c \
				quote_remove.c
EXPAND		= $(addprefix $(EXPANDIR), $(EXPANDFILES))

ENV_DIR		= env/
ENVFILES	= \
				ft_convert_env_to_list.c \
				ft_copy_key.c \
				ft_copy_value.c \
				ft_create_new_env_node.c \
				ft_del_env.c \
				ft_env_err.c \
				ft_env_fail.c \
				ft_get_env_len.c \
				ft_get_key_len.c \
				ft_get_value_len.c
ENV			= $(addprefix $(ENV_DIR), $(ENVFILES)))

UTILDIR		= utils/
UTILFILES	= \
				ft_free_tabs.c
UTILS		=

LIBFTPATH	= ./libft/
LIBFT 		= $(LIBFTPATH)/libft.a
MAKE_LIBFT	= make -C $(LIBFTPATH)
LIBFLAGS	= -L $(LIBFTPATH) -lft -lreadline

INCDIR		= ./inc/

SRCS_DIR	= ./srcs/
SRCS		= \
				$(PARSE)
				$(EXPAND)
				$(ENV)
				$(UTILS)
				main.c
SRCS		= $(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR	= 
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

CC			= cc
CFLAGS		= -g3 -Wall -Wextra -Werror
IFLAGS		= -I $(INC_DIR)

all: $(TARGET)

$(TARGET): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) LIB_FLAGS$()

$(BUILD_DIR)/%o: $(SRCS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE_LIBFT)

-include $(DEPS)

clean:
	@rm -rf $(BUILD_DIR) $(OBJS) $(DEPS)
	@$(MAKE_LIBFT) clean

fclean: clean
	@rm -rf $(TARGET)
	@$(MAKE_LIBFT) fclean

re: fclean
	make all
	$(MAKE_LIBFFT) re

.PHONY: all clean fclean re
