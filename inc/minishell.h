/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/28 12:17:50 by ftuernal         ###   ########.fr       */
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
int			append_cmd_node(t_token *cmd_line, char *line);
bool		check_quotes(char *input);
int			count_token(char *line);
void		delall(t_data *in);
t_token		*cmdline_new_node(char *input);
t_token		*goto_last_node(t_token *ptr);
int			parse_input(t_data *in);
int 		parsing_verif(t_token *cmd_line);
bool		quote_on(const char *input, int index);
char 		**sep_cmdline(char *line);
int 		set_end_word(char *line, int start);
int 		set_start_word(char *line, int i);
int			split_into_words(t_data *in);
void		strerr_parsing(char *str);
void	    tokenizer(t_token *cmd_line);
int			verif_last_token(t_type last_token, t_type type);
int			verif_token(t_type type, t_type last_token);

//DEBUG FUNCTIONS
void		print_all_words(t_token *cmd_line);
//void		delall(t_data *in);


/*
*******************************************************************************
******************************************************************** EXPANDER
*******************************************************************************
*/
int			expand(t_token *cmd_line);
int			expand_noquote_word(t_token *cmd_line, char *word);
int			expand_quote_word(t_token *cmd_line, char *word);
char		*expand_var(char *word);
char		*quote_remove(char *str);
char		*replace_by_env_value(char *word);
char		*replace_by_last_ret(char *word);
char		*replace_var_by_value(char *ptr);
t_quote		set_quote_type(char quote);
void		substitute_word(t_token *cmd_line, char *substitute);

/*
*******************************************************************************
************************************************************************** EXEC
*******************************************************************************
*/
//void		exec_cmd(t_data *in, t_exec *cmd);
void		addback_exec_node(t_cmd *cmd, t_cmd *new);
int			append_rdir_node(t_cmd *cmd, t_token *expand_cmdline);
int			append_arg_node(t_cmd *cmd, t_token *expand_cmdline);
void		close_fdtab(t_cmd *cmd);
char		*copy_path(char **envp);
int			create_heredoc(int type);
char		**create_path(char **envp);
char		**convert_arg_to_tab(t_token *arg);
void		do_child_wait(int pid);
void		do_pipe(t_cmd **cmd);
void		do_process(t_cmd *cmd);
int			exec(t_data *in);
int			exec_child(t_cmd *cmd, t_cmd *start);
void		exec_fork(t_cmd *cmd, t_cmd *start);
void		exec_heredoc_failure(int fd_save);
int			exec_list_create(t_cmd **cmd, t_token *expand_cmdline);
int			exec_new_node_alloc(t_cmd **cmd);
int			exec_rdir_append(t_cmd *cmd);
int			exec_rdir(t_cmd *cmd);
int			exec_rdir_heredoc(t_cmd *cmd);
int			exec_rdir_rin(t_cmd *cmd);
int			exec_rdir_rout(t_cmd *cmd);
char		*expand_heredoc_var(char *line);
int			ft_strcmp(char *s1, char *s2);
int			get_execarglen(t_token *arg);
t_cmd		*goto_exec_last_node(t_cmd *head);
int			heredoc_expand(t_token *rdir);
int			heredoc_no_expand(t_token *rdir);
char		*init_path(char *cmd, char **envp);
void		lauch_execution(t_cmd *cmd);


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
char		*ft_add_var_to_env(t_env **env, char *add);
void		ft_add_to_env(char *to_add);
void		ft_del_from_env(char *to_del);
void		ft_del_env(void);
void		ft_init_env(int ac, char **av, char **env);
void		ft_modif_shlvl(void);
t_env		*ft_create_env_list(char **env);
t_env		*ft_del_node(t_env *env, char *to_del);
t_env		*ft_get_last_env(t_env *env);
t_env		**ft_get_all_env(void);
t_env		**ft_get_env(char **env, char *to_add, char *to_del);
t_env		**ft_get_all_env(void);
// ----------------------------------------------------------------------export
int			ft_check_cpy(char **cpy);
int			ft_get_key_len(char *var);
char		*ft_get_key(char *var);
void		ft_does_value_exist(char *var);

// -----------------------------------------------------------------------unset
int			ft_check_var_to_unset(char *var);
int			ft_exec_unset(t_token *token);

// ------------------------------------------------------------------------echo
int			ft_check_n_flag(char *input);
int			ft_exec_echo(t_token *token, int fd);

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
int			ft_str_is_digit(char **str);
char		*ft_remove_quotes(char *var);

// ----------------------------------------------------------------------export
int			ft_check_cpy(char **cpy);
int			ft_get_key_len(char *var);
int			ft_exec_export(t_token *token);
char		*ft_get_key(char *var);
void		ft_does_value_exist(char *var);

// -------------------------------------------------------------------------pwd
int			ft_exec_pwd(int fd);

// -----------------------------------------------------------------------unset
int			ft_check_var_to_unset(char *var);
int			ft_exec_unset(t_token *token);

/*
*******************************************************************************
************************************************************************ SIGNAL
*******************************************************************************
*/
void		ft_handle_signal(int sig);
void		ft_init_signal(int type);
void		ft_sig_heredoc(int sig);

/*
*******************************************************************************
*********************************************************************** UTILS_2
*******************************************************************************
*/
int			ft_get_tab_len(char **tab);
int 		get_tab_len(char **tab);
char		*ft_add_slash(char const *s1, char const *s2);
char		*ft_check_cmd_for_builtins(char *path, char *cmd);
void		ft_free_all_env(t_env *env);
void		ft_free_cmd(t_cmd *cmd);
void		ft_free_tabs(char **tab);
void		ft_del_tokens(t_token *tokens);
char		*ft_join_all_str(char **split);

int			ft_print_error_msg(char *msg);
int			ft_print_exit_error(t_cmd *cmd, char *var);
void		ft_print_cmd_error(char *cmd);
void		ft_print_sig_error(void);
void		ft_print_export_error(char *err);
void		ft_print_unset_error(char *err);
void		ft_print_redir_error(char *file);

void    	free_2_tabs(char **s1, char **s2);
void		siginit(int type);
void		heredoc_sig(int sig);
int			is_quote(char c);
int			is_quote_heredoc(t_token *rdir);
char		*join_free(char *s1, char *s2, char *ptr);
t_env		**get_env(char **env);
t_token		*ft_delete_all(t_token **node);

//DEBUG
int ft_printenv(t_env *env);
int 		set_sigval(int new_sig);

#endif // !MINISHELL_H
