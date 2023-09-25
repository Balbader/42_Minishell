/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:16 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
# include "../TOOLS/libtools/libtools.h"
# include "../TOOLS/ft_printf/ft_printf.h"
# include "../TOOLS/minishelltools/minishelltools.h"
*/
# include "structures.h"
# include "define.h"
# include "../libft/includes/libft.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <stdio.h>

/*
 *********************************************************************** GLOBAL
*/
extern int	g_error;

/*
*******************************************************************************
************************************************************************ PARSER
*******************************************************************************
*/

t_token		*add_all_words_nodes(char **tab);
void		addback_cmdline_node(t_token **cmd_line, t_token *new);
int			alloc_parse_struct(t_data *in);
int			append_cmd_node(t_token *cmd_line, char *line);
bool		check_quotes(char *input);
int			count_token(char *line);
void		del_all_nodes(t_data *in);
t_token		*cmdline_new_node(char *input);
int			cust_getenv(t_data *in, char **env);
t_token		*goto_last_node(t_token *ptr);
int			parse_input(t_data *in/*, char **env*/);
bool		quote_on(const char *input, int index);
char 		**sep_cmdline(char *line);
int 		set_end_word(char *line, int start);
int 		set_start_word(char *line, int i);
int			split_into_words(t_data *in);
void	    tokenizer(t_token *cmd_line);

//DEBUG FUNCTIONS
void		print_all_words(t_token *cmd_line);
void		delall(t_data *in);

/*
*******************************************************************************
************************************************************************** EXEC
*******************************************************************************
*/
void		exec_cmd(t_data *in, t_exec *cmd);


/*
*******************************************************************************
********************************************************************** BUILTINS
*******************************************************************************
*/

// -------------------------------------------------------------------------env
int			ft_exec_env(int fd);
int			ft_compare_keys(char *key, char *to_find);
int 		ft_get_env_len(t_env *env);
char		**ft_convert_env_to_tab(t_env *env);
char		*ft_find_value(char *var);
void		ft_add_to_env(char *to_add);
void		ft_del_from_env(char *to_del);
void		ft_del_env(void);
void		ft_init_env(int ac, char **av, char **env);
void		ft_modif_shlvl(void);
t_env		*ft_add_var_to_env(t_env *env, char *to_add);
t_env		*ft_create_env_list(char **env);
t_env		*ft_del_node(t_env *env, char *to_del);
t_env		*ft_get_last_env(t_env *env);
t_env		**ft_get_env(char **env, char *to_add, char *to_del);
t_env		**ft_get_all_env(void);

// --------------------------------------------------------------------------cd
int			ft_exec_cd(t_token *token, int in, int out);
int			ft_get_token_len(t_token *token);
void		ft_change_working_directory(void);
void		ft_create_working_directory(void);
void		ft_get_cd_path(char **path);
void		ft_replace_working_directory(void);

// ------------------------------------------------------------------------echo
int			ft_check_n_flag(char *input);
int			ft_exec_echo(t_token *token, int fd);

// ------------------------------------------------------------------------exit
int			ft_exec_exit(t_token *token, t_cmd *cmd);
int			ft_print_exit_error(t_data *data, char *var);
int			ft_str_is_digit(char **str);
char		*ft_remove_quotes(char *var);

// ----------------------------------------------------------------------export
int			ft_check_cpy(char **cpy);
int			ft_get_key_len(char *var);
char		*ft_get_key(char *var);
void		ft_does_value_exist(char *var);

// -------------------------------------------------------------------------pwd
int			ft_exec_pwd(int fd);

// -----------------------------------------------------------------------unset
int			ft_check_var_to_unset(char *var);
int			ft_exec_unset(t_token *token);

/*
*******************************************************************************
*********************************************************************** UTILS_2
*******************************************************************************
*/
int			ft_print_error_msg(char *msg);
int			ft_get_env_len(char **env);
char		*ft_check_cmd_for_builtins(char *path, char *cmd);
void		ft_free_tabs(char **tab);
void		ft_del_tokens(t_token *tokens);
void		ft_print_cmd_error(char *cmd);
void		ft_print_sig_error(void);
void		ft_print_export_error(char *err);
void		ft_print_unset_error(char *err);
void		ft_print_redir_error(char *file);



























#endif // !MINISHELL_H
