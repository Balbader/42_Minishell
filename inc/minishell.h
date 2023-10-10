/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 15:18:17 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "define.h"
# include "enum.h"
# include "structures.h"
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

/******************************************************************** GLOBABL */
extern int	g_error;

/********************************************************************* PARSER */
int			append_cmd_node(t_token *cmd_line, char *line);
int			set_end_word(char *line, int start);
int			set_start_word(char *line, int i);
int			split_into_words(char *in);
int			count_token(char *line);
int			parse_input(char *in);
int			parsing_verif(t_token *cmd_line);
int			tokenizer(t_token *cmd_line);
int			verif_last_token(t_type last_token, t_type type);
int			verif_token(t_type type, t_type last_token);
bool		check_quotes(char *input);
bool		quote_on(const char *input, int index);
char		**sep_cmdline(char *line);
void		addback_cmdline_node(t_token **cmd_line, t_token *new);
void		strerr_parsing(char *str);
t_token		*add_all_words_nodes(char **tab);
t_token		*cmdline_new_node(char *input);
t_token		*goto_last_node(t_token *ptr);

/******************************************************************* EXPANDER */
int			count_quote_words(char *word);
int			dollar_word_count(char *str);
int			expand(t_token *cmd_line);
int			expand_noquote_word(t_token *cmd_line, char *word);
int			expand_quote_word(t_token *cmd_line, char *word);
int			set_dollar_end(char *str, int start);
int			set_dollar_start(char *str, int i);
int			set_end_qword(char *word, int start);
int			set_start_qword(char *word, int i);
int			skip_var_char(char *str);
bool		is_var_char(char c);
char		**sep_in_dollar_word(char *str);
char		*expand_var(char *word);
char		*dup_quote_word(char *word, t_quote qtype);
char		*dup_str_until(char *str, int lim);
char		*dup_var_word(char *str);
char		*quote_remove(char *str);
char		*replace_by_env_value(char *word);
char		*replace_var_by_value(char *ptr);
char		**sep_quote_wrod(char *word);
void		substitute_word(t_token *cmd_line, char *substitute);
t_quote		set_quote_type(char quote);

/*********************************************************************** EXEC */
int			ft_get_cmd_tab_len(char ***tab);
int			append_rdir_node(t_cmd **cmd, t_token *expand_cmdline);
int			append_args_node(t_cmd **cmd, t_token *expand_cmdline);
int			create_heredoc(int type);
int			exec_child(t_cmd *cmd, t_cmd *start);
int			exec_list_create(t_cmd **cmd, t_token *expand_cmdline);
int			exec_new_node_alloc(t_cmd **cmd);
int			exec_rdir_append(t_cmd *cmd);
int			exec_rdir(t_cmd *cmd);
int			exec_rdir_heredoc(t_cmd *cmd);
int			exec_rdir_rin(t_cmd *cmd);
int			exec_rdir_rout(t_cmd *cmd);
int			ft_strcmp(char *s1, char *s2);
int			get_arg_len(t_token *arg);
int			heredoc_expand(t_token *rdir);
int			heredoc_no_expand(t_token *rdir);
char		*init_path(char *cmd);
char		*expand_heredoc_var(char *line);
char		**join_all_2str_tabs(char ***cmd_tab);
char		*copy_path(void);
char		**create_path(void);
char		**convert_arg_to_tab(t_token *arg);
void		addback_exec_node(t_cmd *cmd, t_cmd *new);
void		free_big_tab(char ***tab);
void		close_fdtab(t_cmd *cmd);
void		do_child_wait(int pid);
void		do_pipe(t_cmd **cmd);
void		do_process(t_cmd *cmd);
void		exec(t_token *in);
void		exec_fork(t_cmd *cmd, t_cmd *start);
void		exec_heredoc_failure(int fd_save);
void		launch_execution(t_cmd *cmd);
void		rm_command_node(t_cmd **head, t_cmd *rm_node);
void		ft_del_t_cmd(t_cmd *cmd);
t_cmd		*goto_exec_last_node(t_cmd *head);

/******************************************************************* BUILTINS */
// env
int			ft_exec_env(int fd);
int			ft_compare_keys(char *key, char *to_find);
int			ft_get_env_len(t_env *env);
int			ft_get_value_len(char *var);
char		**ft_convert_env_to_tab(t_env *env);
char		*ft_find_value(char *var);
char		*ft_get_key_section(char *var, char *key);
char		*ft_get_value_section(char *var, char *value);
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

// export
int			ft_check_cpy(char **cpy);
int			ft_get_key_len(char *var);
char		*ft_get_key(char *var);
char		*ft_copy_key_and_equal(char *var, char *new_key);
void		ft_does_value_exist(char *var);

// unset
int			ft_check_var_to_unset(char *var);
int			ft_exec_unset(t_token *token);

// echo
int			ft_check_n_flag(char *input);
int			ft_exec_echo(t_token *token, int fd);

// cd
int			ft_exec_cd(t_token *token, int in, int out);
int			ft_get_token_len(t_token *token);
void		ft_change_working_directory(void);
void		ft_create_working_directory(void);
void		ft_get_cd_path(char **path);
void		ft_replace_working_directory(void);

// echo
int			ft_check_n_flag(char *input);
int			ft_exec_echo(t_token *token, int fd);

// exit
int			ft_exec_exit(t_token *token, t_cmd *cmd);
int			ft_str_is_digit(char **str);
char		*ft_remove_quotes(char *var);

// export
int			ft_check_cpy(char **cpy);
int			ft_get_key_len(char *var);
int			ft_exec_export(t_token *token);
char		*ft_get_key(char *var);
void		ft_does_value_exist(char *var);

// pwd
int			ft_exec_pwd(int fd);

// unset
int			ft_check_var_to_unset(char *var);
int			ft_exec_unset(t_token *token);

/********************************************************************* SIGNAL */
void		error_signal(void);
void		ft_handle_signal(int sig);
void		ft_init_signal(int type);
void		ft_sig_heredoc(int sig);

/********************************************************************** UTILS */
int			ft_get_tab_len(char **tab);
int			ft_run_builtins(char *path, t_cmd *cmd);
int			ft_print_error_msg(char *msg);
int			ft_print_exit_error(t_cmd *cmd, char *var);
int			get_tab_len(char **tab);
int			is_quote(char c);
int			is_quote_heredoc(t_token *rdir);
bool		ft_strchr_bool(const char *s, int c);
char		*ft_add_slash(char const *s1, char const *s2);
char		*ft_check_cmd_for_builtins(char *path, char *cmd);
char		*ft_join_all_str(char **split);
char		*join_free(char *s1, char *s2, char *ptr);
char		**loop_joinf(char **split_path, char *charset);
void		add_str_to_dump(char **paths, t_list *dump);
void		dump_add(void *content, t_list *garbage);
void		dump_del(t_list *garbage);
void		ft_free_all_env(t_env *env);
void		ft_free_cmd(t_cmd *cmd);
void		ft_free_tabs(char **tab);
void		ft_del_tokens(t_token *tokens);
void		ft_print_cmd_error(char *cmd);
void		ft_print_sig_error(void);
void		ft_print_export_error(char *err);
void		ft_print_unset_error(char *err);
void		ft_print_redir_error(char *file);
void		free_2_tabs(char **s1, char **s2);
void		heredoc_sig(int sig);
t_env		**get_env(char **env);
t_token		*ft_delete_all(t_token **node);

#endif // !MINISHELL_H
